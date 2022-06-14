// sliding window techique
O(N)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
         int n = arr.size(); int sum = 0;
        int i=0,j=0;
        int ans = INT_MAX;
        for(int j=0;j<n;j++){
            sum += arr[j]; 
            while(i<n and sum>=target){
                 ans = min(ans,j-i+1);
                 sum -= arr[i]; i++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};






O(N logN)
class Solution {
public:
    bool check(int len,int target, vector<int>& nums){
        int sum = 0; int n = nums.size(); 
        for(int i=0;i<len;i++){
            sum += nums[i]; 
        }
        if(sum>=target) return true;
        for(int i=len;i<n;i++){
            sum = sum + nums[i] - nums[i-len];
            if(sum>=target) return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
         int l=0,r=n-1;
        int ans = 0;
        while(l<=r){
            int mid = (l+r)>>1;
            if(check(mid,target,nums))
                ans = mid, r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};




Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
