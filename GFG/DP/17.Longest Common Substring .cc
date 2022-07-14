class Solution{
public:
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                  dp[i][j] = 1 + dp[i-1][j-1];
                 else
                  dp[i][j] = 0;
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++)
               ans = max(ans, dp[i][j]);
       }
       return ans; 
    }
    };

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB"
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.
