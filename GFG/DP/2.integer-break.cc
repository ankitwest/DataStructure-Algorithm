// Leetcode

// Return the maximum product you can get
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp,-10,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        // dp[2]=1;
        // fun(n) = k*max(fun(n-k),n-k);
        for(int i=2;i<=n;i++){
            for(int k=1;k<i;k++){
                int x = k*(max(dp[i-k],i-k));
                dp[i] = max( dp[i] , x );
            }
        }
        return dp[n];
    }
};
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
