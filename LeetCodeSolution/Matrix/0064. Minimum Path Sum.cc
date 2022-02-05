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

    
    
    
    M-2
    class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        
        //base case
        dp[n-1][m-1] = grid[n-1][m-1];
        
        for(int i=n-2;i>=0;i--){
            dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
        }
        
        for(int j=m-2;j>=0;j--){
            dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                 dp[i][j] = min(dp[i+1][j],dp[i][j+1]) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};
