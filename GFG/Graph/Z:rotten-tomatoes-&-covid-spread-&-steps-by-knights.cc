// Rotten Oranges
class Solution{
  public:
  //Function to find minimum time required to rot all oranges. 
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
       int timer=0;
       int cnt=0;
       int dx[]={0,0,-1,1};
       int dy[]={1,-1,0,0};
       while(!q.empty()){
           int sz=q.size();
           
        for(int i=0;i<sz;i++){
           auto p = q.front();q.pop();
           int x = p.first; int y=p.second;
           for(int k=0;k<4;k++){
               int new_x=x+dx[k]; int new_y=y+dy[k];
               if(new_x>=0 and new_y>=0 and new_x<n and new_y<m and grid[new_x][new_y]==1){
                   grid[new_x][new_y]=2;
                   q.push({new_x,new_y});
                   cnt++;
               }
           }
         }
         if(q.empty()) break;
         timer++;
       }
        
    if(cnt==fresh) return timer;
    return -1;
    }
};
Expected Time Complexity: O(n*m)

  
	
	
	
	
  // Covid Spread     time based
class Infected{
    public:
    int row,col,time;
    Infected(int r,int c,int t){
        row=r;
        col=c;
        time=t;
    }
};
class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
       queue<Infected> q; 
       int uninfected=0;
        int n=hospital.size(); int m=hospital[0].size();
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(hospital[i][j]==1) uninfected++;
               else if(hospital[i][j]==2) q.push(Infected(i,j,0));
           }
       }
       int timer =0;
       int cnt=0; int t=0;
        int dx[] = {-1, +1, 0, 0};
        int dy[] = {0, 0, -1, +1};
       while(!q.empty()){
           int sz = q.size();
          for(int i=0;i<sz;i++){
              auto p = q.front(); q.pop();
              int x=p.row; int y = p.col;  t = p.time;
               for(int k=0;k<4;k++){
                   int new_x=x+dx[k]; int new_y=y+dy[k];
                   if(new_x>=0 and new_y>=0 and new_x<n and new_y<m and hospital[new_x][new_y]==1){
                       hospital[new_x][new_y]=2;
                       q.push(Infected(new_x,new_y,t+1));
                       cnt++;
                   }
               }
          }
          if(q.empty()) break;
          timer++;
       }
       
       if(cnt==uninfected) return timer; // return t;
       return -1;
    }
};
	



  
  
  // Steps by Knight
  class Solution{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int ctr=0; int n=N,m=N;
	   queue<pair<int,int>>q;
	   vector<vector<bool>> vis(N,vector<bool>(N,false));
	   int dx[8]={2,2,1,-1,1,-1,-2,-2};
	   int dy[8]={1,-1,2,2,-2,-2,1,-1};
	   int a = KnightPos[0]-1; int b = KnightPos[1]-1;
	   int c = TargetPos[0]-1; int d = TargetPos[1]-1;
	   if(a==c and b==d) return 0;
	   q.push({a,b});
	   vis[c][d]=true;
	   while(!q.empty()){
	    int sz=q.size();
        ctr++;
        for(int i=0;i<sz;i++){
	       auto p = q.front();q.pop();
	       int x = p.first; int y=p.second;
	  
           for(int k=0;k<8;k++){
               int new_x=x+dx[k]; int new_y=y+dy[k];
               if(new_x==c and new_y==d) return ctr;
               if(new_x>=0 and new_y>=0 and new_x<n and new_y<m and !vis[new_x][new_y]){
                   q.push({new_x,new_y});
                   vis[new_x][new_y]=1;
               }
             }
	       }
	   }
	   return -1;
	}
  };

Expected Time Complexity: O(N2).
