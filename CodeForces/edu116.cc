#include <bits/stdc++.h>
using namespace std;

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpi                  vector<pii>
#define vvi                  vector<vector<int>>
#define pb          push_back
#define ff          first
#define ss          second

#define sz(s)       s.size()   //for vector as well as string   int len=sz(s)
#define fill0(v)        fill(all(v),0);
#define mem0(arr)   memset(arr, 0, sizeof(arr))    //for array
// v.resize(n,x)    //previous element are not disturbed when size is increased 1 2 3 4 5 9 9 9 9 9 9 9 
// vi v1;  v1.assign(v.begin(),v.begin()+5); v1.assign(7, 100); v1.assign({ 1, 2, 3 });
// count(all(v),number) -> to count the occurence of x in vector  
#define lb(v,x) lower_bound(v.begin(),v.end(),x) - v.begin();
#define ub(v,x) upper_bound(v.begin(),v.end(),x) - v.begin();
#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define all(v)      v.begin(),v.end()
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl

#define ll long long
#define int long long
const int mod  =  1e9+7;
const int INF  =  1e18;

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }
int pow(int x, int y,int mod){ int res = 1; x = x % mod;
    while (y) {
        if(y & 1)  res = (res * x) % mod;
        x = (x * x) % mod; y = y>>1;
    }
    return res;
}
int modinv(int n){return pow(n, mod-2);}
int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int mod_sub(int a, int b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int mod_div(int a, int b) {return (mod_mul(a, modinv(b)) + mod) % mod;}

void solveC(){
    int n,k;cin>>n>>k;
    vi a(n); rep(i,0,n) cin>>a[i];
    k++;
    vi deno(n);
    rep(i,0,n) deno[i] = pow(10,a[i],INF);

    vi canUse(n);
    rep(i,0,n) canUse[i] = deno[i+1]/deno[i] -1LL;

    int ans = 0;
    rep(i,0,n-1){
        int notes = min(canUse[i],k);
        int val = notes*deno[i]; 
        ans += val;
        k -= notes;

        if(k<0) break;

    }

    if(k>0){
        ans += k*deno[n-1];
    }

    debug(ans);


}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("hey.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i+1 << ": ";

    return 0;
}

