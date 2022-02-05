class Solution {
public:
    vector<vector<int>> dp;
    int n;int m;
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i==n-1 and j==m-1)
            return grid[i][j];
        if(i>=n or j>=m)
            return 1e6;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int curr = grid[i][j] + min(solve(grid,i+1,j),solve(grid,i,j+1));
        
        return dp[i][j] = curr;
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        
        return  solve(grid,0,0);
    }
};


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
