

class Solution {
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
