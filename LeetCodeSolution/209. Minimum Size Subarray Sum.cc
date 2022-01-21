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
         int l=0,r=n;
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




M-2
  class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int l=0,r=0; int n = arr.size(); int sum = 0;
        int ans = INT_MAX;
        while(r<n){
            sum += arr[r]; 
            while(sum>=target){
                 ans = min(ans,r-l+1);
                 sum -= arr[l]; l++;
            }
            r++;
        }
        return ans==INT_MAX?0:ans;
    }
};
