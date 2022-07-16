class Solution{
public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node,vector<bool> &vis,vector<int> adj[]){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int ans = -1;
	   vector<bool> vis(V,false);
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           dfs(i,vis,adj);
	           ans = i;
	       }
	   }
	   //vis = vector<bool>(V,false);
	   fill(vis.begin(),vis.end(),false);
	   dfs(ans,vis,adj);
	   
	   for(int i=0;i<V;i++){
	       if(vis[i]==false) return -1;
	   }
	   return ans;
	}
};
