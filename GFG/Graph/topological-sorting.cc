class Solution{
public:
	stack<int>st;
	vector<int> res;
	void findTopoSort(int node,vector<int> adj[],bool vis[]){
	    vis[node]=1;
	    for(auto neigh:adj[node]){
	        if(!vis[neigh])
	            findTopoSort(neigh,adj,vis);
	    }
	    st.push(node);
	} 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   
	   bool vis[V];memset(vis,0,sizeof(vis));
	   for(int i=0;i<V;i++){
	       if(!vis[i])
	        findTopoSort(i,adj,vis);
	   }
	   
	   while(!st.empty()){
	       int x = st.top();st.pop();
	       res.push_back(x);
	   }
	   return res;
	}
};


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).
