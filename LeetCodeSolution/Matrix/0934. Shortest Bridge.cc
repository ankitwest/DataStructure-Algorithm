// dfs to mark island 1 vis 
// bfs to find the min dist btw island 1 and island 2
class Solution {
    const int d[5] = {1,0,-1,0,1};
    queue<pair<int,int>> q;
    vector<vector<bool>> vis;
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or vis[i][j]==true or grid[i][j]==0) return;
        
        q.push({i,j});
        vis[i][j] = true;
        
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vis.resize(n,vector<bool>(m,false));
        bool found = false;
        for(int i=0;i<n and !found;i++)
            for(int j=0;j<m and !found;j++)
                if(grid[i][j]==1){ dfs(i,j,grid); found = true; break;}
         
        
        int bridge = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto [x,y] = q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int a = x + d[k]; int b = y + d[k+1];
                    if(a>=0 and b>=0 and a<n and b<m and !vis[a][b])
                    {
                        if(grid[a][b]==1) 
                            return bridge;
                        vis[a][b] = true;
                        q.push({a,b});
                    }
                }
            }
            bridge++;
        }
        return -1;
    }
};


Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

