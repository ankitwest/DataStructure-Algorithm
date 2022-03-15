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
        
        vector<long> da(n,LONG_MAX),db(n,LONG_MAX),dd(n,LONG_MAX);
        
        auto dijkstra = [&](vector<pair<long, long>> adj[],long src,vector<long> &dist){
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
        };
    
        dijkstra(G,a,da);
        dijkstra(G,b,db);
        dijkstra(R,dest,dd);
        
        long ans = LONG_MAX;
        for(int i=0;i<n;i++){
            if(da[i]==LONG_MAX or db[i]==LONG_MAX or dd[i]==LONG_MAX) continue;
            ans = min(ans, da[i] + db[i] + dd[i]);
        }
        
        return ans==LONG_MAX ? -1 : ans;
            
    }
};
