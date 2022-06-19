class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isValid(vector<vector<int>> &grid,int a,int b){
        if(a<0 or b<0 or a>=grid.size() or b>=grid[0].size() or grid[a][b]==-1) return false;
        return true;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int start_x = 0,start_y = 0;
        int empty = 0;
        
        int ans = 0; 
        auto dfs = [&](auto dfs,int x,int y,int cnt)->void{
            if(grid[x][y]==2){
                if(cnt==empty) ans++;
                return;
            }
            
            for(int k=0;k<4;k++){
                int a = x+dx[k]; int b = y+dy[k];
                if(isValid(grid,a,b)){
                    grid[x][y] = -1;  //marked vis
                    cnt++;
                    dfs(dfs,a,b,cnt); 
                    grid[x][y] = 0;  //unmarked vis
                    cnt--;
                }
            }
        };
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) start_x = i,start_y = j;
                else if(grid[i][j]==0 or grid[i][j]==2)  empty++;
            }
        }
        
        grid[start_x][start_y] = -1;  // marked vis
        dfs(dfs,start_x,start_y,0);
        return ans;
    }
};



class Solution1 {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int start_x = 0,start_y = 0;
        int empty = 0;
        
        int ans = 0; 
        auto dfs = [&](auto dfs,int x,int y,int cnt)->void{
            if(x<0 or y<0 or x==n or y==m or grid[x][y]==-1) return;
            if(grid[x][y]==2){
                if(cnt==empty) ans++;
                return;
            }
            
            grid[x][y]=-1;
            cnt++;
            
           
            dfs(dfs,x+1,y,cnt);
            dfs(dfs,x-1,y,cnt);
            dfs(dfs,x,y+1,cnt);
            dfs(dfs,x,y-1,cnt);
            
            //backtrack
            grid[x][y]=0;
            cnt--;
        };
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) start_x = i,start_y = j;
                else if(grid[i][j]==0 or grid[i][j]==2)  empty++;
            }
        }
        dfs(dfs,start_x,start_y,0);
        return ans;
    }
};


You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

