

//bfs 

class Solution {
public:
    const vector<pair<int,int>> d = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        if(grid[0][0] or grid[n-1][m-1]) return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0}); 
        grid[0][0] = 1; 
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int x = curr.first; int y = curr.second;
            if(x==n-1 and y==m-1) return grid[n-1][m-1];
            
            for(int k=0;k<8;k++){
                int new_x = x + d[k].first; int new_y = y + d[k].second;
                if(new_x>=0 and new_y>=0 and new_x<n and new_y<m and grid[new_x][new_y]==0){
                    q.push({new_x,new_y});
                    grid[new_x][new_y] = grid[x][y] + 1;
                }
            }
        }
        return -1;
    }
};
