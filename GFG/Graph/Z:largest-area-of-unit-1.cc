class Solution{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(int x,int y,vector<vector<int>>& grid,int &ctr,int n,int m){
        if(x<0 or y<0 or x>=n or y>=m or grid[x][y]==0) return ;
        if(grid[x][y]==2) return;
        grid[x][y]=2;
        ctr++;
        
       int dx[]={-1,-1,-1,0,0,1,1,1};
       int dy[]={-1,0,1,-1,1,-1,0,1};
        for(int k=0;k<8;k++){
            int new_x=x+dx[k]; int new_y=y+dy[k];
            dfs(new_x,new_y,grid,ctr,n,m);
        }
        // dfs(x+1,y,grid,ctr,n,m);
        // dfs(x-1,y,grid,ctr,n,m);
        // dfs(x,y+1,grid,ctr,n,m);
        // dfs(x,y-1,grid,ctr,n,m);
        // dfs(x+1,y+1,grid,ctr,n,m);
        // dfs(x-1,y-1,grid,ctr,n,m);
        // dfs(x+1,y-1,grid,ctr,n,m);
        // dfs(x-1,y+1,grid,ctr,n,m);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int ctr=0; int maxi = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ctr=0;
                    dfs(i,j,grid,ctr,n,m);
                }
                maxi = max(maxi,ctr);
            }
        }
        return maxi;
    }
};
Expected Time Complexity: O(n*m)
