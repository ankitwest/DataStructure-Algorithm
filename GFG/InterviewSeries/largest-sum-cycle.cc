Juspay

class Solution
{
  public:
  vector<int> vis;
    vector<vector<int>> adj;
    vector<int> parent;
     vector<int> tmp;
  
  long long dfs(int node,int p=-1){
      vis[node]=1;
      parent[node]=p;
      tmp.push_back(node);
      for(auto child:adj[node]){
          if(!vis[child]){
              long long z = dfs(child,node);
              if(z!=-1) return z;
          }else if(vis[child]){
              long long sum=child;
              while(node!=child){
                 sum += node;
                 node = parent[node];
              }
              if(node==child) return sum;
              return -1;
          }
      }
       return -1;
  }
  long long largestSumCycle(int N, vector<int> Edge)
  {
    long long ans = -1;
    
    vis.resize(N); fill(vis.begin(),vis.end(),0);
    adj.resize(N);
    parent.resize(N);
    
    for(int i=0;i<N;i++){
        if(Edge[i]!=-1)
            adj[i].push_back(Edge[i]);
    }
    
    for(int i=0;i<N;i++){
        if(!vis[i]){
            ans = max(ans,dfs(i));
            for(auto j:tmp){ vis[j]=2; }
            tmp.clear();
        }
    }
    
    return ans;
  }
};
