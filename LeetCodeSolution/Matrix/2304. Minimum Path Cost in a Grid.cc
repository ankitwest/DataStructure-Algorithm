class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j){
        if(i==grid.size()-1)
            return grid[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=0; k < moveCost[grid[i][j]].size(); k++)
            mini = min(mini,grid[i][j] + moveCost[grid[i][j]][k] + solve(grid,moveCost,i+1,k));
        
        return dp[i][j] = mini;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(); int m = grid[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int ans = INT_MAX;
        for(int j=0; j<m; j++)
            ans = min(ans, solve(grid, moveCost,0,j));
        return ans;
    }
};
