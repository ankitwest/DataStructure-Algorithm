
class Solution{
  public:
  bool checkBFS(int color[],vector<int> adj[],int node){
      queue<int>q;
      q.push(node);
      color[node]=1;
      while(!q.empty()){
          int curr = q.front(); q.pop();
          for(auto neigh:adj[curr]){
              if(color[neigh]==-1){
                  color[neigh]=1^color[curr];
                  q.push(neigh);
              }else if(color[neigh]==color[curr])
                  return false;
          }
      }
      return true;
  }

  bool checkDFS(int color[],vector<int> adj[],int node){
      for(auto x:adj[node]){
          if(color[x]==-1){
              color[x]=1^color[node];
              if(!checkDFS(color,adj,x)) return false;
          }else if(color[x]==color[node])
              return false;
      }
      return true;
  }

	bool isBipartite(int V, vector<int>adj[]){
	   int color[V];
	   memset(color,-1,sizeof(color));
	   for(int i=0;i<V;i++){
	       if(color[i]==-1){
	           color[i]=1;
	        if(!checkBFS(color,adj,i)) return false;
	       }
	   }
	   	return true;
	}
};
