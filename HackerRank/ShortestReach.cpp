#include <bits/stdc++.h>
using namespace std;

void bfs(int n, int m, vector<vector<int>> adj, int s) {
    vector<int> dist(n+1,-1);
    
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
        int curr = q.front();q.pop();
        for(auto child : adj[curr]){
            if(dist[child]==-1){
                // cout<<child<<" ";
            dist[child]=dist[curr]+6;
            q.push(child);
            }
        }
        
    }
    // cout<<endl;
    
    for(int i=1;i<dist.size();i++){
        if(dist[i]!=0)
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    
}
   

int main (){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
         vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int s;cin>>s;
        
        bfs(n,m,adj,s);
    }
    
    return 0;
}
