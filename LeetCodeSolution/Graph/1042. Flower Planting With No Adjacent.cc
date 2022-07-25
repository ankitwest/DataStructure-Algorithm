class Solution {
    void dfs(int node,vector<int>& col, vector<int> adj[]){
        for(int i=1;i<=4;i++){
            bool f = true;
            for(auto it: adj[node]){
                 if(col[it] == i){
                     f = false;
                     break;
                 }
            }
            if(f==true){
                col[node] = i;
                break;
            }
        }
        
        for(auto it: adj[node]){
            if(col[it] == -1)
                dfs(it, col, adj);
        }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for(auto v:paths){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> col(n+1,-1);
        for(int i=1;i<=n;i++){
            if(col[i] == -1){
                dfs(i, col, adj);
            }
        }
        
        col.erase(col.begin());
        return col;
    }
};
