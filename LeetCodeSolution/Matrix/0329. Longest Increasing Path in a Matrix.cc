class Solution1 {
public:
    //DP to store and dfs to make calls to neighbours
    vector<vector<int>> dp; int n,m;
    int dfs(int i,int j,vector<vector<int>> &mat,int pre){
        if(i<0 or j<0 or i>=n or j>=m or mat[i][j]<=pre) return 0;
        
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        int l = dfs(i,j-1,mat,mat[i][j]);
        int r = dfs(i,j+1,mat,mat[i][j]);
        int u = dfs(i-1,j,mat,mat[i][j]);
        int d = dfs(i+1,j,mat,mat[i][j]);
        
        int tot = max({l,r,u,d}) + 1;
        return dp[i][j] = tot;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size(); m = mat[0].size();
        dp.resize(n,vector<int>(m,-1));
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(i,j,mat,-1));
            }
        }
        
        return ans;
    }
};




class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<int>> dp; int n,m;
    int dfs(int i,int j,vector<vector<int>> &mat){
        if(i<0 or j<0 or i>=n or j>=m) return 0;
        
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        int ans = 0;
        for(int k=0;k<4;k++){
            int a = i+dx[k]; int b = j+dy[k];
            if(a>=0 && b>=0 && a<n && b<m){
                if(mat[i][j] > mat[a][b]){
                    ans = max(ans, 1 + dfs(a,b,mat));
                }
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size(); m = mat[0].size();
        dp.resize(n,vector<int>(m,-1));
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(i,j,mat));
            }
        }
        
        return ans+1;
    }
};


