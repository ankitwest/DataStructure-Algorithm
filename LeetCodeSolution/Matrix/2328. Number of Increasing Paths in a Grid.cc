class Solution {
    int d[5] = {0,-1,0,1,0};
    int mod = 1e9 + 7;
    vector<vector<long long>> dp;
    long long dfs(vector<vector<int>>& grid,int i,int j,int prev){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]<=prev) return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        long long ans = 0;
        for(int k=0;k<4;k++){
            long long t = dfs(grid,i+d[k],j+d[k+1],grid[i][j]);
            ans = (ans + t)%mod;
        }
        
        return dp[i][j] = ans + 1;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        dp.resize(n,vector<long long>(m,-1));
        long long total_path = 0; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total_path = (total_path + dfs(grid,i,j,-1))%mod;
            }
        }
        
        return total_path % mod;
    }
};
