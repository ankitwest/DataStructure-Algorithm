class Solution {
    void dfs(int node,vector<bool>& vis,vector<int> adj[],int& count){
        vis[node] = true;
        for(auto ch: adj[node]){
            if(!vis[abs(ch)]){
                if(ch > 0) count++; 
                dfs(abs(ch), vis, adj, count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto c : connections){
            adj[c[0]].push_back( c[1]);
            adj[c[1]].push_back( -c[0]);
        }
        vector<bool> vis(n,false);
        
        int count = 0;
        dfs(0,vis,adj,count);
        return count;
    }
};


