
class Solution
{
    public:
    int ans =0;
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0) return ;
        if(grid[i][j]==1 or grid[i][j]==2) ans++ ;
        grid[i][j]=0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){    // or grid[i][j]==2
                    dfs(i,j,grid);
                    return (ans==2);
                }
            }
        }
      return 0;
    }
};


Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
 
