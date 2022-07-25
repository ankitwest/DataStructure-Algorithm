class Solution{
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int V = n;
	    vector<int> dist(V,INT_MAX);
	    dist[0]=0;
	    for(int i=0;i<V-1;i++){
	        for(auto edge:edges){
	            if(dist[edge[0]]==INT_MAX) continue;
	            if(dist[edge[0]]+edge[2]<dist[edge[1]]){
	                dist[edge[1]]=dist[edge[0]]+edge[2];
	            }
	        }
	    }
	    
	    for(auto edge:edges){
	            if(dist[edge[0]]+edge[2]<dist[edge[1]]){
	               return 1;
	            }
	        }
	   return 0;
	}
};
Expected Time Complexity: O(E*V);




/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
class Solution{
public:
    vector <int> bellman_ford(int V, vector<vector<int>> edges, int S) {
        vector<int> dist(V,100000000);
        dist[S] = 0;
        
        for(int i=0;i<V-1;i++){
            for(auto edge: edges){
	         if(dist[edge[0]]==1e8) continue;
	         if(dist[edge[0]] + edge[2] < dist[edge[1]]){
	             dist[edge[1]] = dist[edge[0]] + edge[2];
	         }
	    }
        }
        
        for(auto edge: edges){
            if(dist[edge[0]] == 1e8) continue;
            if(dist[edge[0]] + edge[2] < dist[edge[1]]){
                vector<int> temp(V,1e8);
                return temp;
            }
        }
    
        return dist;
    }
};
	
