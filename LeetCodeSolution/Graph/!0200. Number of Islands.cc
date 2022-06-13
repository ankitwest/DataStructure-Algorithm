

class Solution {
public:
    void eraseIslands(vector<vector<char>>& grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0')
            return ;
        
        grid[i][j]='0';
        eraseIslands(grid,i+1,j);
        eraseIslands(grid,i-1,j);
        eraseIslands(grid,i,j+1);
        eraseIslands(grid,i,j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]=='1'){
                   islands++;
                   eraseIslands(grid,i,j);
               }
            }
        }
        return islands;
    }
};

//dfs better

class Solution2 {
public:
    // int dx[]={1,0,-1,0};
    // int dy[]={0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int islands=0;
        int dir[]={0,1,0,-1,0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                     islands++;
                    grid[i][j]='0';

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> curr_pos= q.front(); q.pop();
                        for(int k=0;k<4;k++){
                            int r=curr_pos.first+dir[k] , c = curr_pos.second+dir[k+1];
                            if(r>=0 and c>=0 and r<m and c<n and grid[r][c]=='1'){
                                grid[r][c]='0';
                                q.push({r,c});
                            }
                        }

                    }

                }
            }
        }
        return islands;
    }
};


Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
