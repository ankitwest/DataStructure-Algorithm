class Solution {
public: 
    vector<vector<int>> dp;
    int solve(string s1, string s2,int i,int j){
        if(i==0 or j==0)
            return i+j;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s1[i-1] == s2[j-1])
            dp[i][j] = solve(s1,s2,i-1,j-1);
        else
            dp[i][j] = 1 + min(solve(s1,s2,i-1,j) , solve(s1,s2,i,j-1));
        
        return dp[i][j];
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();int m = s2.size();
        dp.resize(n+1,vector<int> (m+1,-1));
        return solve(s1,s2,n,m);
    }
};

class Solution2 {
public:  
    int minDistance(string s1, string s2) {
        int n = s1.size();int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i=0;i<=n;i++)
            dp[i][0] = i;
        for(int j=0;j<=m;j++)
            dp[0][j] = j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
            }
        }
       
        return dp[n][m];
    }
};

class Solution3 {
public:     // using lcs
    int minDistance(string s1, string s2) {
        int n = s1.size();int m = s2.size();
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
        int uncommon1 = n - dp[n][m];
        int uncommon2 = m - dp[n][m];
        return uncommon1 + uncommon2;
    }
};

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
