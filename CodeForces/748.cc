//Div 3  Oct 13

#include <bits/stdc++.h>
using namespace std;

#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >

#define precision(n) fixed<<setprecision(n)
#define setprecision(n,ans) cout << fixed << setprecision(9) << ans<<endl

#define setbits(x) __builtin_popcountll(x)

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpi                  vector<pii>

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
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;

int exp(int x, int y);
int modinv(int n){return exp(n, mod-2);}
int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int mod_sub(int a, int b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int mod_div(int a, int b) {return (mod_mul(a, modinv(b)) + mod) % mod;}

void solveA()  {
        int a,b,c;  cin>>a>>b>>c;
        int maxi = max(a,max(b,c));
        
        if(a==b and b==c) {
        	a=1;
        	b=1;
        	c=1;
        	debug3(a,b,c); return;
        }else if(a==b and maxi==a){
        	a=1;b=1;c=maxi-c+1;
        }else if(c==b and maxi==b){
        	c=1;b=1;a=maxi-a+1;
        }else if(a==c and maxi==c){
        	a=1;c=1;b=maxi-b+1;
        }else{
    	if(a<maxi) a = maxi -a +1; else if(a==maxi) a = 0;
        if(b<maxi) b = maxi -b +1; else if(b==maxi) b = 0;
        if(c<maxi) c = maxi -c +1; else if(c==maxi) c = 0;
        }	
        
        debug3(a,b,c);

}
void solveB(){
	int n;cin>>n;
	int a[10];
	memset(a,0,sizeof(a));
	int ctr=0;
	while(n){
		if(n%10>0 and a[0]>1){ debug(ctr-a[0]); return;}

		if((n%10==2 or n%10==7) and a[5]) { debug(ctr-1); return;}

		if(n%10==5 and a[0]) { debug(ctr-1); return;}

		a[n%10]++;
		n/=10;
		ctr++;
	}
}
void solveC(){
	int n,k;cin>>n>>k;
	int arr[k];
	rep(i,0,k) cin>>arr[i];

	sort(arr,arr+k);
	reverse(arr,arr+k);

	int ctr=0;
	int sum=0;
	rep(i,0,k){
		sum+=n-arr[i];
		if(sum==n) break;
		else if(sum>n) {break;}
		else ctr++;
	}
	debug(ctr);
} 

void solveD1(){
		int n;
		cin >> n;
 
		vector<int> a(n);
		tr(x,a) cin >> x;
 		
 		sort(all(a));
		int g = 0;
		rep(i,1,n) {
			g = gcd(g, abs(a[i] - a[0]));
			// g = gcd(g, abs(a[i] - a[i - 1]));
		}
 
		if (g == 0) debug(-1); else debug(g);
}

const int maxN  = 4e5+5;
vector<int> adj[maxN];
int vis[maxN];
int deg[maxN];
int n,k;

void clean(){
	for(int i=1;i<=n;i++){
		adj[i].clear();
		// vis[i]=0;
		// deg[i]=0;
	}
}

void solveE(){
	cin>>n>>k;
	int nodes=n;
	int edges=n-1;
	memset(vis,0,sizeof(vis));
	memset(deg,0,sizeof(deg));
	clean();

	for(int i = 1;i <= edges;++i) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++;deg[b]++;
	}
	
	   if(n == 1) {cout<<0<<endl; return;}
	
	vector<int> leaves;
	for(int i=1;i<=n;i++){
		if(deg[i]==1) deg[i]--,leaves.push_back(i);
	}

	while(k>0 and !leaves.empty()){
		vector<int> new_leaves;
		for(auto leaf:leaves){
			vis[leaf]=1;
			for(auto v:adj[leaf]){
				deg[v]--;
				if(deg[v]==1) new_leaves.push_back(v);
			}
		}
		k--;
		leaves=new_leaves;
	}

	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0) ans++;
	}
	cout<<ans<<endl;

}

void solveG(){
	string s;
        cin>>s;
        int sum[s.size()];
        sum[0]=0;
        for (int i=0;i<s.size();i++) {
            sum[i+1]=sum[i];
            if (s[i]=='['||s[i]==']') {
                if (i%2==1) sum[i+1]++;
                else sum[i+1]--;
            }
        }
        int q;
        cin>>q;
        for (int i=1;i<=q;i++) {
        	int l,r;
            cin>>l>>r;
            cout<<abs(sum[r]-sum[l-1])<<endl;
        }
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input2.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve();       

    return 0;
}

int exp(int x, int y){
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







