 typedef pair<long, long> ipair;
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int a, int b, int dest) {
        vector<pair<long,long>> G[n],R[n];
        for(auto e:edges){
            long a = e[0], b = e[1], wt = e[2];
            G[a].push_back({b,wt});
            R[b].push_back({a,wt});
        }
        
          auto dijkstra = [&](vector<pair<long, long>> adj[],long src)->vector<long>{
            vector<long> dist(n,LONG_MAX);
            priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
            pq.push({0,src});
            dist[src] = 0;
            
            while(!pq.empty()){
                auto [cost, u] = pq.top(); pq.pop();
                if (cost > dist[u]) continue;
                
                for(auto &neigh : adj[u]){
                    auto [v,wt] = neigh;
                    
                    if(dist[v]>dist[u]+wt){
                        dist[v] = dist[u] + wt;
                        pq.push({dist[v],v});
                    }
                }
            }
            return dist;
        };
    
        vector<long> da = dijkstra(G,a);
        vector<long> db = dijkstra(G,b);
        vector<long> dd = dijkstra(R,dest);
        
        long ans = LONG_MAX;
        for(int i=0;i<n;i++){
            if(da[i]==LONG_MAX or db[i]==LONG_MAX or dd[i]==LONG_MAX) continue;
            ans = min(ans, da[i] + db[i] + dd[i]);
        }
        
        return ans==LONG_MAX ? -1 : ans;
            
    }
};




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
