
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
Graph
    vector <int> dijkstra(int N, vector<vector<int>> adj[], int src){
        set<pair<int, int>> s;
    	vector<int> dist(N, INT_MAX);
    
    	s.insert({0, src});
    	dist[src] = 0; 
    
    	while(!s.empty()){
    		auto itr = *s.begin(); s.erase(itr);
    		// int dis = itr.first;
    		int u = itr.second;
    		
    		for(auto neigh:adj[u]){
    			int v = neigh[0];
    			int wt = neigh[1];
    
    			if(dist[u] + wt < dist[v]){
    				dist[v] = dist[u] + wt;
    				s.insert({dist[v], v});
    			}
    		}
    	}
    	return dist;
    }



Matrix
//sau
class Solution {
public:
    int dx[4] = {-1 , 1 , 0 , 0};
    int dy[4] = {0 , 0 , -1 , 1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size() , m = maze[0].size();
        int x = entrance[0] , y = entrance[1];
        
        vector<vector<int>> v(n , vector<int>(m , INT_MAX));
        
        v[x][y] = 0;
        set<pair<int,pair<int,int>>> s;
        
        s.insert({0 , {x , y}});
        
        while(s.size())
        {
            auto tp = *s.begin(); s.erase(s.begin());
            auto dis = tp.first;
            int x1 = tp.second.first;
            int y1 = tp.second.second;
            
            for(int i=0;i<4;i++)
            {
                int a = x1 + dx[i];
                int b = y1 + dy[i];
                
                if(a < n && b < m && a >= 0 && b >= 0 && maze[a][b] != '+')
                {
                    if(v[a][b] > v[x1][y1] + 1)
                    {
                        v[a][b] = (v[x1][y1] + 1);
                        s.insert({v[a][b] , {a , b}});
                    }
                }
            }
        }
 };
