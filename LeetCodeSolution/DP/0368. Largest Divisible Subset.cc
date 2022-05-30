

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;
        
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1); vector<int> prev_idx(n,-1);
        int max_idx = 0; 
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i] % nums[j]==0) and (dp[i] < dp[j]+1)){
                    dp[i] = dp[j]+1;
                    prev_idx[i] = j;
                }
            }
            if(dp[i] > dp[max_idx]){
                max_idx = i;
            }
        }
        
        vector<int> ans;
        int i = max_idx;
        while(i!=-1){
            ans.push_back(nums[i]);
            i = prev_idx[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
