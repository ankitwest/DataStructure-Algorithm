class Solution{
  public:
      int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>> q;
       int fresh=0;
       int n=grid.size(); int m=grid[0].size();
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==1) fresh++;
               else if(grid[i][j]==2) q.push({i,j});
           }
       }
       int timer=-1;
       int dx[]={0,0,-1,1};
       int dy[]={1,-1,0,0};
       while(!q.empty()){
           int sz=q.size();
           timer++;
        for(int i=0;i<sz;i++){
           auto p = q.front();q.pop();
           int x = p.first; int y=p.second;
           for(int k=0;k<4;k++){
               int new_x=x+dx[k]; int new_y=y+dy[k];
               if(new_x>=0 and new_y>=0 and new_x<n and new_y<m and grid[new_x][new_y]==1){
                   grid[new_x][new_y]=2;
                   q.push({new_x,new_y});
                   fresh--;
               }
           }
         }
           
       }
       
       if(fresh>0) return -1;
       else if(timer==-1) return 0;
       return timer;
    }
};
Expected Time Complexity: O(n*m)
