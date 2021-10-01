//Div 2   //Sept 30 2021

#include <bits/stdc++.h>
using namespace std;

#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >

#define precision(n) fixed<<setprecision(n)
#define setprecision(n,ans) cout << fixed << setprecision(9) << ans<<endl

#define setbits(x) __builtin_popcountll(x)

#define rev(i,a)            for(int i = a - 1 ; i>=0 ; i--) 
#define fill(a, x)  memset(a, x, sizeof(a))      //for array
#define lscn(n) scanf("%lld", &n)
#define scn(n) scanf("%d", &n)

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpi                  vector<pii>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define all(x)      x.begin(),x.end()

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;

int exp(int x, int y){
    if(x==0) return 0;
    int res = 1;
    x = x % mod;
    while (y) {
        if(y & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y = y>>1;
    }
    return res;
}
int modinv(int n){
    return exp(n, mod-2);
}
int mod_mul(int a, int b) {
    a = a % mod; b = b % mod;
     return (((a * b) % mod) + mod) % mod;
}
int mod_div(int a,int b){
    return (mod_mul(a,modinv(b))+mod)%mod;
}

void solveA()  {
        int n;cin>>n;
        int x = 2*n;
        int pro=1;
        REP(i,1,x){
            pro = mod_mul(pro,i);
        }
        int ans = mod_div(pro,2LL);
      
        cout<<ans<<endl;
}

void solveB(){
    int n,m,k;cin>>n>>m>>k;
    if(m<n-1 or m>n*(n-1)/2) cn;
    else {
        if(k>3) cy;
        else {
            if(k==3){
                if(n*(n-1)/2<=m) cy; else cn;
            }else if(k==2) {
                if(n==1) cy; else cn;
            }else {
                cn;
            }
        }
        
    }
}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i << ": ";

    return 0;
}

