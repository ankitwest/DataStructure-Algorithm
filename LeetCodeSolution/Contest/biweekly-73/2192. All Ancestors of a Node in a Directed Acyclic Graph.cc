class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<bool> &vis){
        // cout<<node<<endl;
        vis[node]=true;
        for(auto child : adj[node]){
            if(vis[child]==true) continue;
            dfs(child,adj,vis);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int> > ans(n);
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            dfs(i,adj,vis);
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(vis[j]) ans[j].push_back(i);
            }
            // cout<<" "<<endl;
        }
        return ans;
    }
};
