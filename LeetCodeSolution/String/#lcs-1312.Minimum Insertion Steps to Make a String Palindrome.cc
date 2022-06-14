class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string &s){
        if(i>j) return 0;   //base case
        if(i==j) return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = 0;
        if(s[i]==s[j])
            ans = solve(i+1,j-1,s);
        else
            ans = 1 + min(solve(i+1,j,s),solve(i,j-1,s));
        
        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        int n = s.size();
        dp.resize(n,vector<int> (n,-1));
        return solve(0,n-1,s);
    }
};


class Solution2 {
public:  //using lcs
     int minInsertions(string s) {
         int n = s.size(); int m = n;
         vector<vector<int>> dp(n+1,vector<int> (m+1,0));;
         string s2 = s;
         string s1 = s;
         reverse(s2.begin(),s2.end());
         
         for(int i=0;i<=n;i++){
             for(int j=0;j<=m;j++){
                 if(i==0 or j==0)
                     dp[i][j] = 0;
                 else if(s1[i-1]==s2[j-1])
                     dp[i][j] = 1 + dp[i-1][j-1];
                 else 
                     dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
             }
         }
         return n - dp[n][m];
     }
};

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
