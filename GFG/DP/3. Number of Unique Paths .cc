class Solution{
public:
    //Function to find total number of unique paths.
    vector<vector<int>> dp;
    int rec(int i,int j){
        if(i==0 or j==0)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = rec(i-1,j)+rec(i,j-1);
        
        return dp[i][j] = ans;
    }
      int NumberOfPath(int n, int m)
    {
        dp.resize(n,vector<int>(m,-1));
        return rec(n-1,m-1);
      }
  };



class Solution{
public:
    //Function to find total number of unique paths.
    int NumberOfPath(int n, int m)
    {
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0)
                    dp[i][j] = 1;
                else 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

Input:
A = 3, B = 4
Output: 10
Explanation: There are only 10 unique
paths to reach the end of the matrix of
size two from the starting cell of the
matrix.
