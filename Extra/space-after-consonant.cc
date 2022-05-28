
// CAB
C AB 
C AB
CAB 
CAB

// DCB
D C B 
D C B
D CB 
D CB
DC B 
DC B
DCB 
DCB

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

// #define int long long
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

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){       
    if(a.first==b.first)return (a.second > b.second); else return (a.first < b.first); }

/*
#define deb(...) cerr << "(" << #__VA_ARGS__ << "):", my_deb(__VA_ARGS__)
void my_deb() { cerr << endl; }
template<typename Arg, typename... Args> void my_deb(Arg A, Args... B) { cerr<<" "<<A; my_deb(B...); }
*/

set<char> v = {'A','E','I','O','U'};
vector<string> ans;
void recur(string s,int ind,string str){
  if(ind>=s.size()) {
    ans.push_back(str);
    return ;
  }

  char ch = s[ind];
  if(v.find(ch)==v.end())
    {recur(s,ind+1,str+ch+" "); recur(s,ind+1,str+ch);}
  else 
    recur(s,ind+1,str+ch);
}
void solve(){
  ans.clear();
  int n;cin>>n;
  string s; cin>>s;
  string ss = s;
  reverse(all(ss));

  recur(ss,0,"");

  rep(i,0,ans.size()){
    reverse(all(ans[i]));
    cout<<ans[i]<<endl;
  }

  ln;
}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE    
    freopen("233.txt", "r", stdin); freopen("2err.txt", "w", stderr);
#endif  
    int tt=1;  
    cin>>tt;
    while(tt--) 
       solve();
    return 0;
}
