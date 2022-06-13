class Solution {
public:
    int n,m;
    int d[5] = {0,1,0,-1,0};
    bool dfs(vector<vector<int>> &grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==1 or grid[i][j]==2) return false;
        
        if(i==grid.size()-1) return true;
        grid[i][j] = 2;
        
        for(int k=0;k<4;k++){
            if(dfs(grid, i+d[k], j+d[k+1]))
                return true;
        }
        return false;
    }
    bool pathExist(vector<vector<int>>& cells,int d){
        vector<vector<int>> grid(n,vector<int>(m,0));
        for(int i=0;i<=d;i++){
            auto v = cells[i];
            grid[v[0]-1][v[1]-1] = 1;
        }
        
         for(int j=0;j<m;j++){
              if(dfs(grid,0,j))
                  return true;
         }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int sz = cells.size();   n = row , m = col;
        int low = 0; int high = sz-1;
        
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(pathExist(cells,mid))
                ans = mid,low = mid + 1;
            else
                high = mid - 1;
        }
        return ans+1;
    }
};
