class Solution{
  void dfs(int node,int par,vector<int>& vis,vector<int> adj[]){
          vis[node] = 1;
          for(auto ch:adj[node]){
              if(!vis[ch]){
                  dfs(ch,node,vis,adj);
              }
          }
      }
    public:
      int numProvinces(vector<vector<int>> mat, int V) {
          int n = V;
          vector<int> adj[n];
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  if(mat[i][j]==1){
                      adj[i].push_back(j);
                      adj[j].push_back(i);
                  }
              }
          }

          vector<int> vis(n,0);
          int cc = 0;
          for(int i=0;i<n;i++){
              if(!vis[i]){
                  dfs(i,-1,vis,adj);
                  cc++;
              }
          }

          return cc;
      }
    };
