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

void solve()  {
        int n,m;  cin>>n>>m;
        string s;cin>>s;
        int p[m];
        rep(i,0,m) cin>>p[i];

		vector<int> cnt(n);
		rep(i,0,m)  cnt[p[i]-1]++;
		    
		

        for (int i = n - 1; i > 0; i--) 
	    	cnt[i - 1] += cnt[i];
		

	        vector<int> ans(26);
		rep(i,0,n) 
		   ans[s[i] - 'a'] += cnt[i] + 1;
		

		for (int i = 0; i < 26; ++i) {
			debug0(ans[i]);
		}
		ln;
      
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("ana.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i+1 << ": ";
    return 0;
}
