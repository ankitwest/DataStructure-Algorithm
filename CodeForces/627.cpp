//Div 3
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
int lcm(int a, int b){ return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;

void solveA()  {
        int n;  cin>>n;
        int arr[n]; vi v(n);
        // rep(i,0,n) cin>>arr[i];
        rep(i,0,n) cin>>v[i];
        int odd=0; int even =0;
        rep(i,0,n){
        	if(v[i]&1) odd++;
        	else even++;
        }
        if(odd and even) cn; else cy;
}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef Ankit_KumarZ    
    freopen("input.txt", "r", stdin);
#endif
    int t;  cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i << ": ";

    return 0;
}
