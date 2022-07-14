class Solutionex
{
    public:
    int d[5] = {0,-1,0,1,0};
    int minimumCostPath(vector<vector<int>>& grid) 
     {
         int n = grid.size(); int m = grid[0].size();
         vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
         dist[0][0] = grid[0][0];
         
         priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
         pq.push({dist[0][0],{0,0}});
         
         while(!pq.empty()){
             auto curr = pq.top(); pq.pop();
             int cost = curr.first;
             int x = curr.second.first; int y = curr.second.second;
             
             if(x==n-1 and y==m-1) return dist[n-1][m-1];
             
             for(int k=0;k<4;k++){
                 int new_x = x+d[k]; int new_y = y+d[k+1];
                 if(new_x<0 or new_y<0 or new_x>=n or new_y>=m) continue;
                 if(dist[x][y]+grid[new_x][new_y]<=dist[new_x][new_y]){
                     dist[new_x][new_y] = dist[x][y]+grid[new_x][new_y];
                    pq.push({dist[new_x][new_y],{new_x,new_y}});
                 }
             }
         }
         return -1;
         
     }
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    // vector<vector<int>> dp;
    // int solve(vector<vector<int>>& grid,int i,int j){
    //     if(i==0 and j==0)
    //         return grid[i][j];
    //     if(i<0 or j<0)
    //         return 1e6;
        
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
            
    //     int curr = grid[i][j] + min(solve(grid,i-1,j),solve(grid,i,j-1));
        
    //     return dp[i][j] = curr;
    // }
    
    // vector<vector<int>> dp;
    // int solve(vector<vector<int>>& grid,int i,int j,int n,int m){
    //     if(i==n-1 and j==m-1)
    //         return grid[i][j];
    //     if(i>=n or j>=m)
    //         return 1e6;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
        
    //     int curr = grid[i][j] + min(solve(grid,i+1,j,n,m),solve(grid,i,j+1,n,m));
        
    //     return dp[i][j] = curr;
    // }
    
    // int minimumCostPath(vector<vector<int>>& grid) 
    // {
    //     int n = grid.size(); int m=n;
    //     dp.resize(n,vector<int>(m,-1));
    //     // return solve(grid,n-1,m-1);
    //      return  solve(grid,0,0,n,m);
    // }
    
    //  int minimumCostPath(vector<vector<int>>& grid) 
    //  {
         // for 2 down and right movement only
        //  int n = grid.size(); int m=n;
        //  vector<vector<int>> dp(n,vector<int>(m,-1));
         
        //  dp[0][0] = grid[0][0];
        //  for(int i=1;i<n;i++)
        //     dp[i][0] = dp[i-1][0]+grid[i][0];
        // for(int j=1;j<m;j++)
        //     dp[0][j] = dp[0][j-1]+grid[0][j];
        
        // for(int i=1;i<n;i++){
        //     for(int j=1;j<m;j++){
        //         dp[i][j] = grid[i][j] + min(dp[i-1][j] + dp[i][j-1]);
        //     }
        // }
        // return dp[n-1][m-1];
        
        // int n = grid.size(); int m = grid[0].size();
        // vector<vector<int>> dp(n,vector<int>(m));
        
        // //base case
        // dp[n-1][m-1] = grid[n-1][m-1];
        
        // for(int i=n-2;i>=0;i--){
        //     dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
        // }
        
        // for(int j=m-2;j>=0;j--){
        //     dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
        // }
        
        // for(int i=n-2;i>=0;i--){
        //     for(int j=m-2;j>=0;j--){
        //          dp[i][j] = min(dp[i+1][j],dp[i][j+1]) + grid[i][j];
        //     }
        // }
        // return dp[0][0];
    //  }
};
