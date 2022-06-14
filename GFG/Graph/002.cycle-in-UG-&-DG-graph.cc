
//Cycle in UG graph

class Solution {
public:
     // Function to detect cycle in an undirected graph.
    bool dfs2 (int node,int parent,vector<int> adj[],vector<bool> &vis){
        vis[node]=1;
        for(auto child:adj[node]){
            if(!vis[child]){
                if(dfs(child,node,adj,vis)) return true;
            }else if(vis[child]){
                if(child==parent) continue;
                else if(child!=parent) return true;
            }
        }
        return false;
    }
    
    bool dfs (int node,int parent,vector<int> adj[],vector<bool> &vis){
        vis[node]=1;
        for(auto child:adj[node]){
            if(!vis[child]){
                if(dfs(child,node,adj,vis)) 
                     return true;
            } else if(child!=parent) 
                 return true;
        }
        return false;
    }
    
    bool dfs3 (int node,int parent,vector<int> adj[],vector<bool> &vis){
        vis[node]=1;
        for(auto neigh: adj[node]){
            if(neigh==parent)  continue; //YEH TOH BAAP HAI... OH SHIT NOT GOOD
            
            if(vis[neigh]){
                return true;
            }else if(!vis[neigh]){
                if(dfs(neigh,node,adj,vis)) 
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(dfs(i,-1,adj,vis))
                    return true;
        }
        return false;
    }
};
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)




  //Cycle in DG graph
  
  class Solution {
public:
    bool dfs(int node,int parent,vector<int> adj[],vector<bool> &vis,vector<bool> &anc){
        vis[node]=1;
        anc[node]=1;
        for(auto child:adj[node]){
            // if(child==parent) continue;  // remove this one in directed graph
            if(!vis[child]){
                if(dfs(child,node,adj,vis,anc)) return true;
            }else if(anc[child]==1) return true;
        }
         anc[node]=0;
        return false;
    }
    
   bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,0);
        vector<bool> anc(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(dfs(i,-1,adj,vis,anc))
                    return true;
        }
        return false;
    }
};
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
  
  1->2->3  cycle yes
  1->2->3->4  1->4 cycle no
  
 
