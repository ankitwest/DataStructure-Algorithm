class Solution {
public:
    //Tarjan Algo
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        vector<int> low(n,-1);
        vector<int> id(n,-1);
        int time = 0;
        
        auto dfs = [&](auto dfs,int u,int par)->void{
            id[u] = low[u] = time++;
            for(auto v:adj[u]){
                if(id[v]==-1){
                    dfs(dfs,v,u);
                    //while backtracking, update low value of parent to check if there is a back-edge
                    low[u] = min(low[u],low[v]);
                    
                    //check if the edge is a bridge and not a back-edge from child/sub-graph of child
                    //to it's parent or any of it's ancestors
                    if(id[u]<low[v])
                        ans.push_back({u,v});
                }else if(v!=par){   //backedge
                    //check and update if the ancestor was discovered before the earliest connected node to our current node
                    low[u] = min(low[u],id[v]);
                }
            }
        };
        
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        for(int i=0;i<n;i++){
            if(id[i]==-1)  // dfs(i,-1);
                dfs(dfs,i,-1);
        }
        return ans;
    }
};
