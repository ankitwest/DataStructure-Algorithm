#include <bits/stdc++.h>
using namespace std;

#define all(x)      x.begin(),x.end()
#define sz(s) s.size()   //for vector as well as string   int len=sz(s)
#define mem0(arr)   memset(arr, 0, sizeof(arr))    //for array
#define mem1(arr)   memset(arr, -1, sizeof(arr))   //for array
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

bool comp(pair<int, int> &a,pair<int, int> &b){
        return a.second < b.second;
}

void solve()  {
        int n;  cin>>n;
        vector<int> brr(n);
        rep(i,0,n) cin>>brr[i];

        vector<pair<int,int>> arr;
        rep(i,0,n){
            arr.push_back({brr[i],i});
        }

        int k=0;
        sort(all(arr));
        rep(i,0,n){
            if(arr[i].first>k) 
                arr[i].first = k,k++;
            else if(arr[i].first==k)
                arr[i].first = k;
        }

        sort(arr.begin(),arr.end(),comp);

        rep(i,0,n) debug0(arr[i].first);
        ln;
}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i+1 << ": ";

    return 0;
}

