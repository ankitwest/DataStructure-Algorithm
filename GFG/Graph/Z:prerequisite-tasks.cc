// Detect cycle in Directed Graph

class Solution{
  public:
    bool dfs(int node,vector<int> adj[],bool vis[],int anc[]){
        vis[node]=1; 
        anc[node]=1;
        
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                  if(dfs(neigh,adj,vis,anc)) return true;
            }
            else if(anc[neigh]==1) 
                return true;
            
        }
        anc[node]=0;
        return false;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
    vector<int> adj[N];
    bool vis[N]={0};
    int anc[N]={0};
	   for(auto x:prerequisites){
	       adj[x.first].push_back(x.second);
	   }
	
	   for(int i=0;i<N;i++){
	       if(!vis[i])
	        if(dfs(i,adj,vis,anc)) 
	            return false;
	   }
	   return true;
	}
};
Expected Time Complexity: O(N + P)
