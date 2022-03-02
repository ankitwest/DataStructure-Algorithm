class Solution {
public:
  bool isSubsequence(string t, string s) {
         int n = s.size(); int m = t.size();
         int dp[n+1][m+1];
         memset(dp,0,sizeof(dp));
         for(int i=0;i<=n;i++)
             dp[i][0]=0;
         for(int j=0;j<=m;j++)
             dp[0][j]=0;
         
         for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
                 if(s[i-1]==t[j-1])
                     dp[i][j] = 1+dp[i-1][j-1];
                 else
                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
             }
         }
         return dp[n][m]==t.size()?true:false;
     }
};

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
