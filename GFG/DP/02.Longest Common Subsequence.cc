class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int n = s1.size(); int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int j=0;j<=m;j++)
            dp[0][j] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(s1[i-1]==s2[j-1])
                     dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};


class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s1,string &s2,int n,int m){   // pass by reference otherwise tle
        if(n==0 or m==0)
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        int ans = 0;
        if(s1[n-1]==s2[m-1])
            ans = 1 + solve(s1,s2,n-1,m-1);
        else
            ans = max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
        
        return dp[n][m] = ans;
    }
    int lcs(int x, int y, string s1, string s2){
        int n = s1.size(); int m = s2.size();
        dp.resize(n+1,vector<int> (m+1,-1));
        
        return solve(s1,s2,n,m);
    }
};


A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
