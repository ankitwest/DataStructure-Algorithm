class Solution{
public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        int n = matrix.size(); int m = matrix[0].size();
        queue<pair<int,int>> q;
         vector<vector<int> > dist(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(matrix[i][j]=='B') q.push({i,j});
           }
       }
       
       int d[] = {1,0,-1,0,1};
       int dis=0;
       while(!q.empty()){
           int sz = q.size();
           dis++;
           while(sz--){
               auto cor = q.front(); q.pop();
               int x = cor.first;int y = cor.second;
               for(int k=0;k<4;k++){
                   int new_x = x+d[k]; int new_y = y+d[k+1];
                   if(new_x<0 or new_y<0 or new_x>=n or new_y>=m or matrix[new_x][new_y]=='W' or matrix[new_x][new_y]=='B') continue;
                   if(matrix[new_x][new_y]=='#') continue;
                   if(matrix[new_x][new_y]=='O'){
                       matrix[new_x][new_y]='#';
                       dist[new_x][new_y] = min(dist[new_x][new_y],dis);
                       q.push({new_x,new_y});
                   }
               }
           }
       }
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(matrix[i][j]=='B') dist[i][j] = 0;
               else if(matrix[i][j]=='W') dist[i][j] = -1;
              else if(matrix[i][j]=='O') dist[i][j] = -1;
            //   else if(dist[i][j]==INT_MAX) dist[i][j] = -1;
           }
       }
       return dist;
    } 
};


Input: N = 3, M = 3
A[] = {{O, O, O}, 
       {W, B, B}, 
       {W, O, O}}
Output: {{2, 1, 1}, 
         {-1, 0, 0},  
         {-1, 1, 1}}
