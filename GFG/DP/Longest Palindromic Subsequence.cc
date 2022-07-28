// LPS
class Solution1 {
    int dp[1001][1001];
    int solve(string s1,string s2,int i,int j){
        if(i>j) return 0;
        if(i==j) return s1[i] == s2[j];
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int ans = 0;
        if(s1[i] == s2[j])
            ans = 2 + solve(s1,s2,i+1,j-1);
         else
            ans = max(solve(s1,s2,i+1,j), solve(s1,s2,i,j-1));
        
        return dp[i][j] = ans;
    }
  public:
    int longestPalinSubseq(string A) {
        string B = A; int n = A.size();
        memset(dp,-1,sizeof(dp));
    
        return solve(A,B,0,n-1);
    }
};

// LCS
class Solution2  {
    int dp[1001][1001];
    int solve(string s1,string s2,int i,int j){
        if(i<0 and j<0) return 0;
        if(i<0) return 0;
        if(j<0) return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int ans = 0;
        if(s1[i] == s2[j])
            ans = 1 + solve(s1,s2,i-1,j-1);
         else
            ans = max(solve(s1,s2,i-1,j), solve(s1,s2,i,j-1));
        
        return dp[i][j] = ans;
    }
  public:
    int longestPalinSubseq(string A) {
        string B = A; int n = A.size();
        memset(dp,-1,sizeof(dp));
        reverse(B.begin(),B.end());
        return solve(A,B,n-1,n-1);
    }
};


class Solution{
    int dp[1001][1001];
public:    
    int longestPalinSubseq(string A) {
        string B = A; int n = A.size();
        memset(dp,0,sizeof(dp));
        reverse(B.begin(),B.end());
        
        for(int i=0;i<=n;i++)
           dp[i][0]=0;
       for(int i=0;i<=n;i++)
           dp[0][i]=0;
           
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
               if(A[i-1]==B[j-1])
                   dp[i][j] = 1 + dp[i-1][j-1];
               else
                   dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
       }
       return dp[n][n];
    }
};
