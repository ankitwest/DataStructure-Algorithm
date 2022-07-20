class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st){
        vis[node]=1;
        for(auto x:adj[node])
            if(!vis[x])
                dfs(x,vis,adj,st);
       
        st.push(node);
    }

    void rev_graph_dfs(int node,vector<int> &vis,vector<int> rev_graph[]){
        vis[node]=1;
        for(auto x:rev_graph[node])
            if(!vis[x])
                rev_graph_dfs(x,vis,rev_graph);
       
    }
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        int n=V;
        vector<int> vis(V,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
            dfs(i,vis,adj,st);
        }
        vector<int> rev_graph[V];
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(auto x:adj[i])
                rev_graph[x].push_back(i);
        }
        int scc=0;
        while(!st.empty()){
            int node = st.top();st.pop();
                if(!vis[node]){
                    scc++;rev_graph_dfs(node,vis,rev_graph);
                }
        }
         return scc;
    }
};
Expected Time Complexity: O(V+E).
