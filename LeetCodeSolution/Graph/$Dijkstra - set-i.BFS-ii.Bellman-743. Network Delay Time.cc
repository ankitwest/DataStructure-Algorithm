// BFS   -> can also use Dijkstra with Priority Queue

class Solution1 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<times.size();i++){
            int a = --times[i][0];
            int b = --times[i][1];
            int wt = times[i][2];
            adj[a].push_back({b,wt});
        }
        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX); 
        k--;
        dist[k] = 0;
        q.push({dist[k],k}); 
        
        while(!q.empty()){
            auto [curr_dist,u] = q.front(); q.pop();
            // if(dist[u] < curr_dist) continue;
            
            for(auto child : adj[u]){
                auto [v,wt] = child;

                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u]+wt;
                    q.push({dist[v],v});
                }
            }
        }
        int maxi = *max_element(dist.begin(),dist.end());
        return (maxi==INT_MAX) ? -1 : maxi;
    }
};
Time complexity - O(V+E)

        // dijkstra  
    Time complexity - O(E*logV)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<times.size();i++){
            int a = --times[i][0];
            int b = --times[i][1];
            int wt = times[i][2];
            adj[a].push_back({b,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX); 
        k--;
        dist[k] = 0;
         pq.push({dist[k],k}); 
        
        while(!pq.empty()){
            auto [curr_dist,u]  = pq.top(); pq.pop();
            // if(dist[u] < curr_dist) continue;
            
            for(auto child : adj[u]){
                auto [v,wt] = child;
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxi = *max_element(dist.begin(),dist.end());
        return (maxi==INT_MAX)?-1:maxi;
    }
};



//set
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<times.size();i++){
            int a = --times[i][0];
            int b = --times[i][1];
            int wt = times[i][2];
            adj[a].push_back({b,wt});
        }
        set<pair<int,int>> s;
        vector<int> dist(n,INT_MAX); 
        k--;
        dist[k] = 0;
        s.insert({dist[k],k}); 
        
        while(s.size()){
            auto [curr_dist,u] = *s.begin(); s.erase(s.begin());
            // if(dist[u] > curr_dist) continue;
            
            for(auto child : adj[u]){
                auto [v,wt] = child;
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u]+wt;
                    s.insert({dist[v],v});
                }
            }
        }
        int maxi = *max_element(dist.begin(),dist.end());
        return (maxi==INT_MAX)?-1:maxi;
    }
};

// Bellman Ford

class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,INT_MAX);   
        k--;
        dist[k] =0;
        for(int i=0;i<times.size();i++){
            --times[i][0];
            --times[i][1];
        }
        for(int i=0;i<n;i++){
            for(vector<int> e:times){
                int u = e[0]; 
                int v = e[1]; 
                int wt = e[2];
                if(dist[u] != INT_MAX and dist[u]+wt < dist[v])
                    dist[v] = dist[u]+wt;
            }
        }
        int maxi = *max_element(dist.begin(),dist.end());
        return (maxi==INT_MAX)?-1:maxi;
    }
};


Time complexity - O(VE)
    
    
