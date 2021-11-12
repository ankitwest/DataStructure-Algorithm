
int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	

	cin >> S;

	dijkstra(V,adj,S);


	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";

return 0;	
}

class Solution{
  	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            // int dis = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for(auto neigh : adj[u]){
                    int v = neigh[0];
                    int wt = neigh[1];
                
                if(dist[u]+wt<dist[v])
                {
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};
Expected Time Complexity: O(V^2).
Expected Time Complexity:O(ElogV) maybe
	
	








// using set

//     vector <int> dijkstra(int N, vector<vector<int>> adj[], int src){
//         set<pair<int, int>> s;
//     	vector<int> dist(N, INT_MAX);
    
//     	s.insert({0, src});
//     	dist[src] = 0; 
    
//     	while(!s.empty()){
//     		auto itr = *s.begin();
//     		// int dis = itr.first;
//     		int u = itr.second;
//     		s.erase(itr);
    
//     		for(auto neigh:adj[u]){
//     			int v = neigh[0];
//     			int wt = neigh[1];
    
//     			if(dist[u] + wt < dist[v]){
//     				dist[v] = dist[u] + wt;
//     				s.insert({dist[v], v});
//     			}
//     		}
//     	}
//     	return dist;
//     }
