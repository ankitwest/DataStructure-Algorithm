class Solution1 {
public:
    //Tarjan Algo
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        vector<int> low(n,-1);
        vector<int> discovery(n,-1);  //discovery 
        int time = 0;
        
        auto dfs = [&](auto dfs,int node,int par)->void{
            discovery[node] = low[node] = time++;
            for(auto child : adj[node]){
                if(child == par) continue;
                if(discovery[child] == -1){
                    dfs(dfs,child,node);
                    //while dfs, update low value of parent to check if there is a back-edge
                    low[node] = min(low[node],low[child]);
                    
                    //check if the edge is a bridge and not a back-edge from child/sub-graph of child
                    //to it's parent or any of it's ancestors
                    if(low[child] > discovery[node])
                        ans.push_back({node,child});
                }else if(discovery[child] >= 0){   //backedge   // 1->2->3->1
                    //check and update if the ancestor was discovered before the earliest connected node to our current node
                    low[node] = min(low[node],discovery[child]);
                }
            }
        };
        
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        for(int i=0;i<n;i++){
            if(discovery[i]==-1) 
                dfs(dfs,i,-1);
        }
        return ans;
    }
};




class Solution {
public:
    //Tarjan Algo
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        vector<int> low(n,-1);
        vector<int> discovery(n,-1);  //discovery 
        vector<bool> vis(n,false);
        int time = 0;
        
        auto dfs = [&](auto dfs,int curr,int par)->void{
            vis[curr] = true;
            discovery[curr] = low[curr] = time++;
            
            for(auto next : adj[curr]){
                if(next == par) continue;
                
                if(!vis[next]){
                    dfs(dfs,next,curr);
                    
                    low[curr] = min(low[curr],low[next]);
                    
                    if(low[next] > discovery[curr])
                        ans.push_back({curr,next});
                }else{
                    low[curr] = min(low[curr],discovery[next]);
                }
            }
        };
        
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) 
                dfs(dfs,i,-1);
        }
        return ans;
    }
};
