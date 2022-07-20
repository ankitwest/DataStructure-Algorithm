class Solution
{
public:
    int findNumberOfVertices(int X, int V, vector<vector<int>> adj)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,X});
        vector<int> dist(V+1,INT_MAX);
        dist[X] = 0;
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int dis = curr.first; int x = curr.second;
            
             if (dis > dist[x]) continue;
             
            for(auto v : adj[x]){
                if(dist[x] + 1 < dist[v]){
                    dist[v] = dist[x] + 1;
                    pq.push({dist[v],v});
                }
            }
        }
        
        int cnt = 0;
        for(int i=1;i<=V;i++){
            if(dist[i]%2==0) cnt++;
        }
        return cnt;
    }
    
      int findNumberOfVertices2(int X, int V, vector<vector<int>> adj)
    {
        vector<int> dist(V+1,INT_MAX);
        queue<int> q;
        q.push(X);
        dist[X] = 0;
        vector<int> vis(V+1,false);
        vis[X] = true;
        
        while(!q.empty()){
            int sz = q.size();
            for(int k =0;k<sz;k++){
                auto curr = q.front(); q.pop();
                
                for(auto v:adj[curr]){
                    if(!vis[v]) {
                        if(dist[curr] + 1 < dist[v]){
                            dist[v] = dist[curr] + 1;
                            q.push(v);
                           vis[curr] = true;
                      }
                    }
                    
                    
                }
            }
        }
        
        int cnt = 0;
        for(int i=1;i<=V;i++){
            if(dist[i]%2==0) cnt++;
        }
        return cnt;
    }
};
