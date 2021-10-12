#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000000+1;
vector<vector<int>> adj(maxN);
vector<bool> vis(maxN,false);
vector<int> color(maxN);

int dist; int id;
void bfs(int node){
    vis[node]=1;
    queue<pair<int,int>> q;
    q.push({node,0});
    while(!q.empty()){
        pair<int,int> curr = q.front(); q.pop();
        int cnode=curr.first;
        for(auto &neigh :adj[cnode]){
            if(!vis[neigh]){
            if(color[neigh]==id){
                dist=curr.second+1;
                return ;
                }
                vis[neigh]=1;
                q.push({neigh,curr.second+1});
                
            }
        }
    }
}
int main(){
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        freopen("input.txt", "r", stdin);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        color[i]=a;
    }
    // int id;
    cin>>id;
    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        if(color[i]==id){
             dist=INT_MAX;
             bfs(i);
            ans = min(ans , dist);
        }
    }
    if(ans==INT_MAX)
        cout<<"-1"<<endl;
    else 
        cout<<ans<<endl;
    
}
