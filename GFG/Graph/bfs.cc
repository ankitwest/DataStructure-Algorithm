class Solution {
  public:
  vector<int> res;
  
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       bool vis[V];  memset(vis,0,sizeof(vis));
       
        res.push_back(0);vis[0]=1;
       queue<int> q;
        q.push(0);
         while(!q.empty()){
            int curr=q.front();q.pop();
            for(auto child:adj[curr]){
                 if(!vis[child]){
                res.push_back(child); vis[child]=1;
                q.push(child);
               }
            }
           
        }
        
       return res;
    }
};


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
