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
