class Solution {
  public:
  struct Module{
    int x;
    int y;
    int dist;
    Module(int x,int y,int dist){
        this->x=x;
        this->y=y;
        this->dist=dist;
    }
};

bool isSafe(int new_x,int new_y,vector<vector<int>> &A){
    return (new_x>=0 and new_y>=0 and new_x<A.size() and new_y<A[0].size() and A[new_x][new_y]!=0);
}
    int shortestDistance(int N,int M,vector<vector<int>> A,int X,int Y){
    if(A[0][0]==0) return -1;
    int dx[]={1,-1,0,0};int dy[]={0,0,1,-1};

    queue<Module> q;
    A[0][0]=0;
    q.push(Module(0,0,0));
   
    while(!q.empty()){
        Module curr = q.front(); q.pop();
        if(curr.x==X and curr.y==Y) 
            return curr.dist;

        for(int k=0;k<4;k++){
            int new_x = curr.x + dx[k]; int new_y = curr.y + dy[k];
            if(!isSafe(new_x,new_y,A)) continue;
            A[new_x][new_y]=0;
            q.push(Module(new_x,new_y,curr.dist+1));
        }
    }
    return -1;
 }
};



Expected Time Complexity:O(N*M)
Expected Auxillary Space:O(N*M)
  
  
  
