class Solution {
    const int d[5] =  {-1,0,1,0,-1};
    int n,m;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& mat,int i,int j,int pre){
        if(i<0 or j<0 or i>=n or j>=m or mat[i][j]<=pre) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int tot = 0;
        for(int k=0;k<4;k++){
            int t = dfs(mat,i+d[k],j+d[k+1],mat[i][j]);
            tot = max(tot, t);
        }
        
        return dp[i][j] = tot + 1;
    }
  public:
    int longestIncreasingPath(vector<vector<int>>& mat, int N, int M) {
        n = mat.size(); m = mat[0].size();
        int ans = 0;
        
        dp.resize(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, dfs(mat,i,j,-1));
            }
        }
        return ans;
    }
};





//using vis 
// backtrack
class Solution {
    const int d[5] =  {-1,0,1,0,-1};
    int n,m;
    int dp[1001][1001];
    
    int dfs(vector<vector<int>>& mat,int i,int j,int pre,int vis[][1001]){
        if(i<0 or j<0 or i>=n or j>=m or mat[i][j]<=pre or vis[i][j]) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
            
        vis[i][j] = 1;
        int tot = 0;
        for(int k=0;k<4;k++){
            int t = 1 + dfs(mat,i+d[k],j+d[k+1],mat[i][j],vis);
            tot = max(tot, t);
        }
        vis[i][j] = 0;
        
        return dp[i][j] = tot;
    }
  public:
    int longestIncreasingPath(vector<vector<int>>& mat, int N, int M) {
        n = mat.size(); m = mat[0].size();
        int ans = 0;
        
        memset(dp,-1,sizeof(dp));
        int vis[1001][1001];
        memset(vis,0,sizeof(vis));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, dfs(mat,i,j,-1,vis));
            }
        }
        return ans;
    }
};
