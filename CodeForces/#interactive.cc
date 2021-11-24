#include <bits/stdc++.h>
using namespace std;

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpii                 vector<pii>
#define vvi                  vector<vector<int>>
#define pb          push_back
#define ff          first
#define ss          second

#define fill0(v)        fill(all(v),0);
#define mem0(arr)   memset(arr, 0, sizeof(arr))    //for array
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

#define int long long
#define ll long long
const int mod  =  1e9+7;

ll query(ll l, ll r)
{
    cout << "? " << l << " " << r << endl;
    ll ans;
    cin >> ans;
    return ans;
}

void solve()  {
	ll t, n, i, j, ans, temp, sum;
	string sans;
   sans = "NO";
		ans = temp = sum = 0;
		cin >> n;
		ll total = query(1, n);
		ll l, r, mid;
		ll x1, x2, x3;
		l = 1;
		r = n;
		while (r > l + 1)
		{
			mid = (l + r) / 2;
			if (query(1LL, mid) == total)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		x3 = r;
		ll diff = query(1, x3) - query(1, x3 - 1);
		x2 = x3 - diff;
		if (x2 == 2)
		{
			x1 = 1;
		}
		else
		{
			diff = query(1, x2 - 1) - query(1, x2 - 2);
			x1 = x2 - 1 - diff;
		}
		cout << "! " << x1 << " " << x2 << " " << x3 << endl;
}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("abc.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i+1 << ": ";
    return 0;
}


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
