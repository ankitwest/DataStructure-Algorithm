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
        int n,a,b;  cin>>n>>a>>b;
        string s;cin>>s;

        int ctr=0;
        for(int i=0;i<n;){
            int j=i;
            while(s[i]==s[j]) j++;
            i=j;ctr++;
        }
        int ans=0;
        ans += n*a;
        if(b>=0){
        	ans += n*b;
        }else if(b<0){
            int x = ctr/2 + 1; // reduces by 2  eg. 10101  ctr=5 ; x=3;
            ans += x*b;
        }
        debug(ans);
     
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("ana.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i+1 << ": ";

    return 0;
}

