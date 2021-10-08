#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define all(x)      x.begin(),x.end()
#define ln cout<<"\n";
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;

void solveA(){
	int n,m;cin>>n>>m;
	vector<int> v(n);
	int sum=0;
	rep(i,0,n){
		cin>>v[i];
		
	}
	sum = accumulate(all(v),sum);
	int ans=0;
	if(sum==m) ans=m;
	else if(sum>m) ans = m;
	else if(sum<m)  ans=sum;

	cout<<ans<<endl;
}
void solveB(){
	int n;cin>>n;
	string s;cin>>s;
	 string res = s;
	 int ans=0;
    for (int l=1;l<n;l++) {
        string end = s.substr(l, n-l);
        string beg = s.substr(0, l);
        if ((n-l)%2 == 1) {
            reverse(beg.begin(), beg.end());
        }
        end += beg;
        if (end < res) {
            res = end;
            ans = l;
        }
    }
    cout<<res<<endl;
    cout<<ans+1<<endl;
}
void solveC(){
	int n,m,p;cin>>n>>m>>p;
	vector<int> a(n),b(m);
	rep(i,0,n) cin>>a[i];
	rep(i,0,m) cin>>b[i];

	int x = 0, y = 0;

	rep(i,0,n) 	if(a[i]%p){x=i;break;}
	rep(i,0,m) 	if(b[i]%p){y=i;break;}
	cout << x + y << '\n';

}    
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input2.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solveC();       

    return 0;
}


