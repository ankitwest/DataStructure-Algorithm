class Solution{
public:
	stack<int>st;
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
		
	   vector<int> res;
	   while(!st.empty()){
	       int x = st.top();st.pop();
	       res.push_back(x);
	   }
	   return res;
	}
};


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

	
	//BFS    kahn's algo
	
	class Solution
	{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indeg[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        vector<int> toposort;
        while(!q.empty()){
            auto curr = q.front();q.pop();
            toposort.push_back(curr);
            for(auto neigh:adj[curr]){
                indeg[neigh]--;
                if(indeg[neigh]==0) q.push(neigh);
            }
        }
        
        if(toposort.size()==n) return toposort;
        return {};
    }
	};
