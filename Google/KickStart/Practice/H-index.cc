#include <bits/stdc++.h>
using namespace std;

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
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
#define rev(i,n,a)      for(int i = n ; i >= a  ; i--)
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

template<typename T1, typename T2> static inline int min(const T1 &x,const  T2 &y){ return x<y?x:y; }
template<typename T1, typename T2> static inline int max(const T1 &x,const  T2 &y){ return x>y?x:y; }
template<typename T> inline T gcd(const T& a, const T& b){ return b?gcd(b,a%b):a; }
template<typename T> inline T lcm(const T& a, const T& b){  return a/gcd(a, b)*b; }

int power(int x,int y){ int res=1; while(y){if(y%2==1) res=(res*x); x=(x*x);y=y>>1;}return res;}
int powermod(int x,int y,int m=mod){ int res=1; x=x%mod;while(y){if(y%2==1)  res=(res*x)%mod;x=(x*x)%mod; y=y>>1;}return res;}
int modinv(int n){return power(n, mod-2);}
int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int mod_sub(int a, int b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int mod_div(int a, int b) {return (mod_mul(a, modinv(b)) + mod) % mod;}

/*
#define deb(...) cerr << "(" << #__VA_ARGS__ << "):", my_deb(__VA_ARGS__)
void my_deb() { cerr << endl; }
template<typename Arg, typename... Args> void my_deb(Arg A, Args... B) { cerr<<" "<<A; my_deb(B...); }
*/

const int maxn = 1e5+5;
void solve2(){
    int n;  cin>>n;
    vi a(n);  rep(i,0,n) cin>>a[i];
    vi m(maxn,0);
    vi rank;int ans=0;

    for(int i=0;i<n;i++){
        for(int k=0;k<=a[i];k++){
            m[k]+=1;
        }

        for(int j=1;j<=n;j++){
            if(m[j]==j) ans = j;
        }
        rank.pb(ans);
    }
    print(rank);
}


void solve(){
    int n;  cin>>n;
    vi a(n);  rep(i,0,n) cin>>a[i];

    int hindex=0; vi rank;
    priority_queue< int,vector<int>,greater<int> > pq;
    for(int i=0;i<n;i++){
        if(a[i]>hindex)
            pq.push(a[i]);

        while(pq.size() and pq.top()<=hindex)
            pq.pop();
        if(pq.size()>=hindex+1)
            hindex+=1;
        rank.pb(hindex);
    }
    print(rank);
    // for(int i=0;i<rank.size();i++)
    //     cout<<rank[i]<<" ";
    // ln;
}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE    
    freopen("23.txt", "r", stdin); freopen("2err.txt", "w", stderr);
#endif  
    int tt=1;  
    cin>>tt;
    // while(tt--) 
       // solve(); 
   for(int i=1;i<=tt;i++){
     cout<<"Case #"<<i<<": ";
     solve();
   }
    return 0;
}


2
3
5 1 2
6
1 3 3 2 2 15
  
Case #1: 1 1 2
Case #2: 1 1 2 2 2 3

