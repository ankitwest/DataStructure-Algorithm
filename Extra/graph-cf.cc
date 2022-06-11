#include <bits/stdc++.h>
using namespace std;

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vs                   vector<string>
#define vvs                  vector<vector<string>>
#define vpii                 vector<pair<int, int>>
#define vvi                  vector<vector<int>>
#define pb              push_back
#define ff              first
#define ss              second
#define set_bits(x)             __builtin_popcountll(x)
#define setprecision(n)     cout << fixed << setprecision(n)
#define INF         1e18

#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)
#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()  //rbegin(v),rend(v);
#define cy          cout<<"YES"<<"\n"
#define cn          cout<<"NO"<<"\n"
#define ln          cout<<"\n";
#define cerrln      cerr<<"\n";
#define debug0(x)       cout<<(x)<<" "
#define debug(x)        cout<<(x)<<"\n"
#define debug2(x,y)     cout<<(x)<<" "<<(y)<<"\n"
#define debug3(x,y,z)   cout<<x<<" "<<y<<" "<<z<<"\n"
#define input(v)        tr(x,v)  cin>>x;
#define print(v)        tr(x,v) debug0(x); ln;

#define int long long
const int mod  =  1e9+7;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first==b.first)return (a.second > b.second); else return (a.first < b.first); }

const int N = 300005+1;
vi adj[N];
int subtree[N] , dp[N];

void dfs(int root,int par){
    subtree[root] = 1;
    vi child;
    for(auto node :adj[root]){
        if(node==par) continue;
        dfs(node,root);
        child.pb(node);
        subtree[root] += subtree[node];
    }

    if(child.size()==0)
        dp[root] = 0;
    else if(child.size()==1)
        dp[root] = subtree[child[0]] - 1;
    else if(child.size()==2)
        dp[root] = max(dp[child[0]] + subtree[child[1]] - 1 , dp[child[1]] + subtree[child[0]] - 1);

}

void solve(){
    int n;cin>>n;
    for(int i=0;i<=n;i++) adj[i].clear();

    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,0);
    debug(dp[1]);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("23.txt", "r", stdin); freopen("2err.txt", "w", stderr);
    #endif
    int tt=1;
    cin>>tt;
    while(tt--)
       solve();
    return 0;
}
