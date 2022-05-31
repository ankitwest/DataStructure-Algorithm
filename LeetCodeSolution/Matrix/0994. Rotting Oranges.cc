

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int fresh = 0; 
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==1) fresh++;
               else if(grid[i][j]==2) q.push({i,j});
           }
       }
        if(fresh==0) return 0;
        int d[5] = {0,1,0,-1,0}; 
         
        auto isValid = [&](int x,int y){
            if(x<0 or y<0 or x>=n or y>=m) return false;
            return true;
        };
        int time = 0; 
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto curr = q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int nx = curr.first + d[k];int ny = curr.second + d[k+1];
                    if(isValid(nx,ny) and grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                        fresh--;
                    }
                }
            }
            time++;
            if(fresh==0) break;
        }
        if(fresh>0) return -1;
        return time;
    }
};
