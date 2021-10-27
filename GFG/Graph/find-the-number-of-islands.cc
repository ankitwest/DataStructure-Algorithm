class Solution{
 public:
 void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0' or grid[i][j]=='2' ) return;
        
        grid[i][j]='2';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        
        dfs(i+1,j+1,grid);
        dfs(i-1,j-1,grid);
        dfs(i+1,j-1,grid);
        dfs(i-1,j+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ctr=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1')
                    {dfs(i,j,grid);   ctr++;}
            }
        }
        return ctr;
    }
};
  
  
  
   Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
