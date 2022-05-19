// BFS   -> can also use Dijkstra with Priority Queue

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
        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX); 
        k--;
        dist[k] = 0;
        q.push({k,dist[k]}); 
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            for(auto child : adj[curr.first]){
                int node = child.first;
                int wt = child.second;
                if(dist[curr.first]+wt<dist[node]){
                    dist[node] = dist[curr.first]+wt;
                    q.push({node,dist[node]});
                }
            }
        }
        // int mini = *min_element(dist.begin(),dist.end());
        int maxi = *max_element(dist.begin(),dist.end());
        
        return (maxi==INT_MAX)?-1:maxi;
    }
};

Time complexity - O(V+E)

        // dijkstra
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
        pq.push({k,dist[k]}); 
        
        while(!pq.empty()){
            auto [u,curr_dist] = pq.top(); pq.pop();
            for(auto child : adj[u]){
                auto [v,wt] = child;
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u]+wt;
                    pq.push({v,dist[v]});
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
    
    



// different

