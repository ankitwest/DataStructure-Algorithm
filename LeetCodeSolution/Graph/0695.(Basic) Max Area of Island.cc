

class Solution {
public:
    int n,m;
     int findArea(vector<vector<int>>& grid, int row, int col){
        if(row<0 or col<0 or  row>=n or col>=m or grid[row][col]==0) return 0;
         
        if(grid[row][col]==1)
            grid[row][col]=0;
       
         int total = 1 + findArea(grid,row+1,col) + 
                    findArea(grid,row,col+1) +
                    findArea(grid,row-1,col)+
                    findArea(grid,row,col-1);
         
         return total;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0; int ar=0;
        n = grid.size(),m = grid[0].size();
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==1){
                    ar = findArea(grid,i,j);
                    area=max(area,ar);
                }
            }
        } 
         return area;   
    }
};

// only these two

class Solution1 {
public:
    int findIslandArea(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return 0;
        }
        
        int area = 0;
        if (grid[row][col] == 1) {
            grid[row][col] = 0;
            area = 1 + findIslandArea(grid, row + 1, col) + findIslandArea(grid, row - 1, col)
                + findIslandArea(grid, row, col + 1) + findIslandArea(grid, row, col - 1);
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    area = max(area, findIslandArea(grid, i, j));
                }
            }
        }
        return area;
    }
};

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
