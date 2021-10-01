#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(int m,int n,vector<vector<int>> &adj,int i,vector<int> &vis){
    vis[i]=1;
    int noOfNodes =1;
    for(auto child: adj[i]){
        if(!vis[child])
         noOfNodes+=dfs(m,n,adj,child,vis);
    }
    return noOfNodes;
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n,m,lib,road;
        cin>>n>>m>>lib>>road;
        int m1=m;
        vector<vector<int>> adj(n+1);
        while(m1--){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> vis(n+1,0);
        ll  cost=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int noOfNodes = dfs(m,n,adj,i,vis);
                // cout<<noOfNodes<<endl;
                cost += (ll)lib +(ll)min(lib,road)*(noOfNodes-1);
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}

