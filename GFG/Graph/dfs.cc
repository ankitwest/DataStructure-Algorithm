class Solution{
public:
  vector<int> res;
    // Function to return a list containing the DFS traversal of the graph
    void dfs(int node,vector<int> adj[],bool vis[]){
        vis[node]=1;
        for(auto child:adj[node]){
            if(!vis[child])
                {res.push_back(child); dfs(child,adj,vis);}
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    bool vis[V];
    memset(vis,0,sizeof(vis));
    
    res.push_back(0);
    dfs(0,adj,vis);
    return res;
    }
};


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
