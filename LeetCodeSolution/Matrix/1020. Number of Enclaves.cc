class Solution {
    int dfs(int x,int y,vector<vector<int>>& grid){
        if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y]==0) return 0;
        
        grid[x][y] = 0;
        
        int cnt = 1 + dfs(x+1,y,grid) + dfs(x-1,y,grid) + dfs(x,y+1,grid) + dfs(x,y-1,grid);
        return cnt;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = 0; int reachable = 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (grid[i][j]==1) total += 1;
                    
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1 and (i==0 or j==0 or i==n-1 or j==m-1)) 
                    reachable += dfs(i,j,grid);
            }
        }
        
        int ans = total - reachable;
        return ans;
    }
};




// use in backtracking 
    // const int d[5] = {-1,0,1,0,-1}; 
    // bool isValid(int x,int y,vector<vector<int>>& grid){
    //     if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y]==0) return 0;
    //     return 1;
    // }
    // int dfs(int x,int y,vector<vector<int>>& grid){
    //     int cnt = 1;
    //     for(int k=0;k<4;k++){
    //         int a = x + d[k]; int b = y + d[k+1];
    //         if(isValid(a,b,grid) and grid[a][b] == 1){
    //             grid[a][b] = 0;
    //             cnt += dfs(a,b,grid);
    //         }
    //     }
    //     return cnt;
    // }

