GFG
shortest path using atmost one curved path
#define ipair pair<int,int>
class Solution {
  public:
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> edges) {
        vector<pair<int,int>> adj[n];
        vector<vector<int>> curved;
        a--,b--;
        for(int i=0;i<m;i++){
            auto vc = edges[i]; 
            int u = --vc[0];  int v = --vc[1];
            int w = vc[2];    int cw = vc[3];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            curved.push_back({u,v,cw});
        }
              
        auto dijkstra = [&](vector<pair<int, int>> adj[],int src)->vector<int>{
            vector<int> dist(n,INT_MAX);
            priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
            pq.push({0,src});
            dist[src] = 0;
            
            while(!pq.empty()){
                int u = pq.top().second; pq.pop();
                
                for(auto &neigh : adj[u]){
                    int v = neigh.first;
                    int wt = neigh.second;
                    
                    if(dist[u]+wt < dist[v]){
                        dist[v] = dist[u] + wt;
                        pq.push({dist[v],v});
                    }
                }
            }
            return dist;
        };
    
        vector<int> da = dijkstra(adj,a);
        vector<int> db = dijkstra(adj,b);
        
        int ans = da[b];
        
        // direct from (a to b)
        // OR
        // dist fron (a to x) + one curved path(x to y) + dist from (y to b)
        
        for(int i=0;i<m;i++){
            int u = curved[i][0];
            int v = curved[i][1];
            int cw = curved[i][2];

            ans = min(ans, da[u] + cw + db[v]);
            ans = min(ans, da[v] + cw + db[u]);
        }
        
        return ans;
    }
};
