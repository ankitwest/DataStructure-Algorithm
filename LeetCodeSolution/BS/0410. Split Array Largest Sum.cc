

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        
        auto check = [&](int maxi){
            int sum=0; int cnt=1; int k=m-1;
            for(auto num:nums){
                sum += num;
                if(sum>maxi) sum=num,k--,cnt++;
            }
            return cnt<=m;
        };
        
        int ans=0;
        while(low<=high){
            int mid = (low + high)/2;
            if(check(mid)) 
                high = mid-1,ans = mid;
            else 
                low = mid+1;
        }
       return ans;
    }
};


Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

Input: nums = [1,2,3,4,5], m = 2
Output: 9
