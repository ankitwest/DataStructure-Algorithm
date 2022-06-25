class Solution {
public:
    
    bool dfs(int node, int par, vector<int> &vis,map<int,vector<int>> &adj){
        vis[node]=1;
         for(auto it: adj[node]) {
             if(it==par) continue;
            if(!vis[it]) {
                if(dfs(it, node, vis, adj)) 
                    return true; 
            }
            else if(it!=par) 
                return true; 
        }
        
        return false; 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,vector<int>> adj; int n = edges.size();
        
        for(int i=0;i<n;i++){
            int u = edges[i][0]; int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            vector<int> vis(n+1,0);
            if(dfs(u,-1,vis,adj))
                return {u,v};
            vis.clear();
            
        }
        return {};
       
    }
};


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]



DSU

class Solution2 {
public:
    int find_par(int node,vector<int> &parent){
        if(node==parent[node])
            return node;
        else return parent[node] = find_par(parent[node],parent);
    }
    
    void UNION(int a,int b,vector<int> &parent){
        int x = find_par(a,parent);
        int y = find_par(b,parent);
        
        parent[x]=y;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1005);
        for(int i=0;i<1005;i++)
            parent[i]=i;
        
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0]; int v = edges[i][1];
            int x = find_par(u,parent);
            int y = find_par(v,parent);
            
            if(x==y)
                ans = {u,v};
            else 
                UNION(u,v,parent);
        }
        return ans;
    }
};
