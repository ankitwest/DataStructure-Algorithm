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
