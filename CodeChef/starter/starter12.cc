#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve2(){
    int n;cin>>n;int n1 =n;
    n--;n--;

    if(n1==1) cout<<3<<endl;
    else if (n1==2) cout<<15<<endl;
    else{
        int x = 0;
    string s;
        s+='1';
    while(n--){
        s += '0';
    }
    s+='5';

    cout<<s<<endl;
    }

}

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
 void solve3()  {
    int a,b,c;cin>>a>>b>>c;
    int x,y,z;cin>>x>>y>>z;

    int ans =0;
    REP(i,0,20){
        REP(j,0,20){
            REP(k,0,20){
                if(i*a+j*b+k*c <= 240)
                    ans = max(ans ,i*x+j*y+k*z );
            }
        }
    }
    cout<<ans<<endl;


}

void solve4()  {
    //K - balanced string
        int n;  cin>>n;
        int k;  cin>>k;   
        string s;cin>>s;
        int ctr=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')continue;

            if((s[i+k]=='1' and i+k<n) or (s[i-k]=='1' and i-k>=0)) continue;

            if(i+k<n) s[i+k] = '1';
            else s[i]='0'; 

            ctr++;
        }
        cout<<ctr<<endl;
}

void solve5(){
    //Path
    int n,m,x,y;cin>>n>>m>>x>>y;
    if(n>m) swap(n,m);
     int diff = m-n;

     int c1 = (n-1+m-1)*x;  //y>2x
     int c2 = (n-1)*y + diff*x;   //2x>y>x
     int c3 = (n-1)*y + (diff/2)*2*y + (diff%2)*x;   //x>y

     int ans  = min( {c1 , c2 , c3 });

     cout<<ans<<endl;
}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int t;  cin>>t;
    while(t--) 
       solve2();       // cout << "Case #" << i << ": ";

    return 0;
}


#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxN = 1e6+5;


vector<int> a(maxN) ;
vector<int> bob(maxN) , alice(maxN);
vector<vector<int>> adj(maxN);


void dfs(int u , int par = -1){
    int maxx = -1e15 ; int minn = 1e15 ;  
    for(auto child : adj[u]){
        if(child==u) continue;
        dfs(child,u);
        maxx = max(maxx , alice[child] + a[child]);
        minn = min(minn , bob[child] + a[child]);
    }
    if(minn != INT_MAX){
        alice[u] = minn;
        bob[u] = maxx;
    }
}
int32_t main()
{
         ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        freopen("input.txt", "r", stdin);
    int tests;
    cin>>tests;
    while(tests--)
    {
        int n,k;
        cin>>n>>k;
        
        for(int i=1;i<=n;i++)
        cin>>a[i];

        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);
        cout<<alice[1]<<endl;

    }
    return 0;
}

#include<bits/stdc++.h>
#define int long long int
using namespace std;

void dfs(int i,int p,vector<int>& a,vector<vector<int>>& tree,vector<vector<int>>& dp)
{
    int min1=INT64_MAX, max1=INT64_MIN;
    for(int child: tree[i])
    {
        if(child==p)
        continue;

        dfs(child,i,a,tree,dp);
        min1=min(min1,dp[child][1]+a[child]);
        max1=max(max1,dp[child][0]+a[child]);
    }

    if(min1==INT64_MAX)
    {
         dp[i][0]=dp[i][1]=0;
         return;
    }

    dp[i][0]=min1;
    dp[i][1]=max1;

}

int32_t main()
{
         ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        freopen("input.txt", "r", stdin);
    int tests;
    cin>>tests;
    while(tests--)
    {
        int n,k;
        cin>>n>>k;
        
        vector<int> a(n+1);
        vector<vector<int>> tree(n+1);
        vector<vector<int>> dp(n+1,vector<int>(2)); //0 means Alice 1 means Bob

        for(int i=1;i<=n;i++)
        cin>>a[i];

        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        dfs(1,-1,a,tree,dp);
        cout<<dp[1][0]<<endl;

    }
    return 0;
}


