class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size(); int n = obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n, -1));
        
      auto solve = [&dp,&obs](auto solve,int i,int j){
            if(i<0 or j<0)
                return 0;
          
            if(obs[i][j]==1)
                return 0;
            
            if(i==0 and j==0 and obs[i][j]==0)
                return 1;
            
            if(dp[i][j]!=-1)
                return dp[i][j];
            
            int ways = 0;
            if(obs[i][j]==0)
             ways = solve(solve,i-1,j) + solve(solve,i,j-1);
            
            return dp[i][j] = ways;
        };
        
        return solve(solve,m-1,n-1);
    }
};


class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size(); int n = obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n, 0));
        for(int i=0;i<m;i++){
             if(obs[i][0]==0) dp[i][0]=1;
             else break;
        }
         for(int j=0;j<n;j++){
             if(obs[0][j]==0) dp[0][j]=1;
             else break;
         }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obs[i][j]==1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};



class Solution3 {
public: 
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size(); int n = obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n, -1));
        
        auto solve = [&dp,&obs,&m,&n](auto solve,int i,int j){
            if(i==m or j==n)
                return 0;
            
             if(obs[i][j]==1)
                return 0;
                 
            if(i==m-1 and j==n-1 and obs[i][j]==0)
                return 1;
            
            if(dp[i][j]!=-1)
                return dp[i][j];
            
            int ways = 0;
            if(obs[i][j]==0)
             ways = solve(solve,i+1,j) + solve(solve,i,j+1);
            
            return dp[i][j] = ways;
        };
        return solve(solve,0,0);
     }
};
  

/*
[[1,0]]
[[0,1]]
*/
