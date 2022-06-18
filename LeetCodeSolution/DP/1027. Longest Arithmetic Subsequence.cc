class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
        int maxDiff = 10005;
        vector<vector<int>> dp(n,vector<int> (maxDiff,0));
        
        int maxi = 2;
        for(int i=0;i<n;i++)
            dp[i][0] = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = max(2, dp[j][diff] + 1);
                maxi = max(maxi,dp[i][diff]);
            }
        }
        return maxi;
    }
};

Input: nums = [9,4,7,2,10]
Output: 3
Explanation: 
The longest arithmetic subsequence is [4,7,10].
  
class Solution2 {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
        vector<unordered_map<int,int>> dp(n);
        int maxi = 2;
        
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];
                if(dp[j].find(diff) == dp[j].end()){
                    dp[i][diff] = 2;
                }else{
                     dp[i][diff] = dp[j][diff] + 1;
                }
                maxi = max(maxi,dp[i][diff]);
            }
        }
        return maxi;
    }
};
