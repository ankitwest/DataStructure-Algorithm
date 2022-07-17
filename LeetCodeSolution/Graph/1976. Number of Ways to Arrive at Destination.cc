#define ll long long
#define pll pair<ll, ll>

class Solution {
    const long long mod = 1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto v:roads){
            long long a = v[0];
            long long b = v[1];
            long long w = v[2];
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        
        // dp
        vector<long long> dp(n,0);
        
        //dijkstra
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>> > pq;
        vector<long long> dist(n,INT64_MAX);
        dist[0] = 0;
        pq.push({dist[0],0});
        
        // base case
        dp[0] = 1;  
        
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int dis = curr.first; int u = curr.second;
            
             if (dis > dist[u]) continue;  // Skip if `d` is not updated to latest version!
            
            for(auto p : adj[u]) {
                int v = p.first; int wt = p.second;
                
                //if less
                if(dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                    dp[v] = dp[u];
                }
                //if equal
                else if(dist[u] + wt == dist[v])
                {
                    dp[v] = (dp[v] + dp[u])%mod;
                }
            }
        }
        
        // for(auto i:dp) cout<<i<<" ";
        // cout<<endl;
        
        return (int)(dp[n-1]%mod);
    }
};


