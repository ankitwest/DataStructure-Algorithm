class Solution{
  	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            // int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            for(auto neigh : adj[prev]){
                    int next=neigh[0];
                    int wt=neigh[1];
                
                if(dist[prev]+wt<dist[next])
                {
                    dist[next]=dist[prev]+wt;
                    pq.push({dist[next],next});
                }
            }
        }
        return dist;
    }
};
Expected Time Complexity: O(V^2).
