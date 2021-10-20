//Div 2

#include <bits/stdc++.h>
using namespace std;

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpi                  vector<pii>

#define ff first
#define ss second

#define all(x)      x.begin(),x.end()
#define sz(s) s.size()   //for vector as well as string   int len=sz(s)
#define mem0(arr)   memset(arr, 0, sizeof(arr))    //for array
#define mem1(arr)   memset(arr, -1, sizeof(arr))   //for array
#define fill0(v)     fill(all(v),0);
#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)

#define ln cout<<"\n";
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl

#define int long long
#define ll long long
const int mod  =  1e9+7;

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }
int pow(int x, int y){ int res = 1; x = x % mod;
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

  
void solve(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    rep(i,0,n) cin>>arr[i];

  
    sort(all(arr));
    int ans=0;

    vpi vp(n);
    vi a(n+1);
    fill(all(a),0);

    rep(i,0,k){
        int l,r;cin>>l>>r;
        l--,r--;
        a[l]++;a[r+1]--;
    }
        vi pre(n+1); pre[0]=a[0];
    rep(i,1,n+1){
        pre[i]=pre[i-1]+a[i];
    }
   sort(all(pre));
         

    rep(i,0,arr.size()){
        ans += arr[i]*pre[i+1];
    }
    debug(ans);



}    
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("ana.txt", "r", stdin);
    int t=1;
     // cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i+1 << ": ";

    return 0;
}

