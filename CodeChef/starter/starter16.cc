#include <bits/stdc++.h>
using namespace std;

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpi                  vector<pii>
#define ff first
#define ss second
#define lscn(n) scanf("%lld", &n)
#define all(x)      x.begin(),x.end()
#define sz(s) s.size()   //for vector as well as string   int len=sz(s)
#define mem0(arr)   memset(arr, 0, sizeof(arr))    //for array
#define mem1(arr)   memset(arr, -1, sizeof(arr))   //for array
#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)

#define fill0(v)     fill(all(v),0);
#define lb(v,x) lower_bound(v.begin(),v.end(),x) - v.begin();
#define ub(v,x) upper_bound(v.begin(),v.end(),x) - v.begin();

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

const int maxn = 1e7+5;
bool prime[maxn];
vi prePrime(maxn);
void pre(){
       for(int i=0;i<maxn;i++)
        prime[i]=true;

    prime[0]=prime[1]=false;
 
    for(int p=2;p*p<maxn;p++){
        if(prime[p]){
            for(int i=p*p;i<maxn;i+=p)
                prime[i]=false;
        }
    }

     prePrime[0]=prime[0];

    rep(i,1,maxn){
        prePrime[i]=prePrime[i-1]+prime[i];
    }
     
}

void solve()  {
        int l,r;  cin>>l>>r;

        int ans = r-l-(prePrime[r]-prePrime[l+1]);

        debug(ans);
}
int32_t main(){
    pre();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    int t=1;  
    cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i+1 << ": ";

    return 0;
}






