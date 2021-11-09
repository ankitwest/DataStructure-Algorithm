
//Cycle in UG graph

class Solution {
  public:
  vector<bool> vis;
  bool ans ;
    bool dfs(int node,vector<int> adj[],int parent){
        vis[node]=1;
        for(auto neigh: adj[node]){
            if(neigh==parent)  continue;  //YEH TOH BAAP HAI... OH SHIT NOT GOOD
           
            if(vis[neigh]){
                return true;
            }else if(!vis[neigh]){
                if(dfs(neigh,adj,node)) 
                    return true;
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        vis.resize(V,false);
        ans = false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,-1)) 
                    return true;
            }
        }
        return false;
    }
};
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

  
  
// class Solution {
//   public:
//   vector<bool> vis;
//   bool ans ;
//     void dfs(int node,vector<int> adj[],int parent){
//         vis[node]=1;
//         for(auto neigh: adj[node]){
//             if(neigh==parent)  continue;  //YEH TOH BAAP HAI... OH SHIT NOT GOOD
          
//             if(vis[neigh]){
//                 ans = true; return ;
//             }else if(!vis[neigh]){
//                 dfs(neigh,adj,node);
//             }
//         }
//     }
//     bool isCycle(int V, vector<int> adj[]) {
//         vis.resize(V,false);
//         ans = false;
//         for(int i=0;i<V;i++){
//             if(!vis[i]){
//                  dfs(i,adj,-1);
//             }
//         }
//         return ans;
//     }
// };



  
  
  
  
 
