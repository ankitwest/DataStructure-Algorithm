
// Djikstra's

// not dp approach

// here can move in all four directions

class Solution{
public:
    int d[5] = {0,-1,0,1,0};
    int minimumCostPath(vector<vector<int>>& grid) 
     {
         int n = grid.size(); int m = grid[0].size();
         vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
         dist[0][0] = grid[0][0];
         
         priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
         pq.push({dist[0][0],{0,0}});
         
         while(!pq.empty()){
             auto curr = pq.top(); pq.pop();
             int cost = curr.first;
             int x = curr.second.first; int y = curr.second.second;
             
             if(x==n-1 and y==m-1) return dist[n-1][m-1];
             
             for(int k=0;k<4;k++){
                 int new_x = x+d[k]; int new_y = y+d[k+1];
                 if(new_x<0 or new_y<0 or new_x>=n or new_y>=m) continue;
                 if(dist[x][y]+grid[new_x][new_y]<=dist[new_x][new_y]){
                     dist[new_x][new_y] = dist[x][y]+grid[new_x][new_y];
                    pq.push({dist[new_x][new_y],{new_x,new_y}});
                 }
             }
         }
         return -1;
     }
  };
