

//cycle in DG 
class Solution {
public:   
    bool dfsCycle(vector<int> adj[],vector<int>& vis,int node,int par,vector<int>& anc){
        vis[node] = 1;
        anc[node] = 1;
        for(auto child: adj[node]){
            // if(child==par) continue; //  remove this one in directed graph
            if(!vis[child]){
                if(dfsCycle(adj,vis,child,node,anc)) return true;
            }
            else if(anc[child] == 1){
                return true;
            }
        }
        anc[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(n,0);
        vector<int> anc(n,0);
        bool flag = false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfsCycle(adj,vis,i,-1,anc)) flag = true;
            }
        }
        if(flag) return false;
        return true;
    }
};
