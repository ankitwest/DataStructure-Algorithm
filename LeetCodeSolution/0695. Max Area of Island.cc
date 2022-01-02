class Solution {
private:
      int findArea(vector<vector<int>>& grid, int row, int col)
    {
        int n=grid.size(),m=grid[0].size();
      if(row<0 or col<0 or  row>n-1 or col>m-1 or grid[row][col]==0) return 0;
        grid[row][col]=0;
       
         return 1 + findArea(grid,row+1,col) + findArea(grid,row,col+1) +
                findArea(grid,row-1,col)+
                findArea(grid,row,col-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==1){
                    int find = findArea(grid,i,j);
                    area=max(area,find);
                }
            }
        } 
         return area;   
    }
};
