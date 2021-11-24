#include <bits/stdc++.h>
using namespace std;

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpi                  vector<pii>
#define vvi                  vector<vector<int>>
#define pb          push_back
#define ff          first
#define ss          second

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
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

void solve2(){
	int n;cin>>n;
	vi a(n); mii m1;
	rep(i,0,n) {
		cin>>a[i];
		m1[a[i]]++;
	}
	vvi v;
	v.pb(a);

	while(1){
		vi new_a(n); mii m2; 
		rep(i,0,n) {
			new_a[i]=m1[a[i]];
			m2[new_a[i]]++;
		}
		if(new_a==a) break;
		else{
			v.pb(new_a);
			swap(m1,m2);
			swap(a,new_a);
		}
	}

	int q;cin>>q;
	while(q--){
		int pos,k; cin>>pos>>k;
		
		if(k>=v.size()) 
			debug(v[v.size()-1][pos-1]);
		else 
			debug(v[k][pos-1]);
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hey.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve2();       // cout << "Case #" << i+1 << ": ";

    return 0;
}








void solveC() {  //Array Elimination
	int T = read();
	while (T--) {
		n = read();
		for (int i = 0; i < 30; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			int x = read();
			for (int j = 0; j < 30; j++)
				if (x >> j & 1) ++cnt[j];
		}
		for (int i = 1; i <= n; i++) {
			bool pd = 1;
			for (int j = 0; j < 30; j++) pd &= (cnt[j] % i) == 0;
			if (pd) printf("%d ", i);
		}
		puts("");
	}
	return ;
}
void solveC(){ //Array Elimination
	std::cin >> n;
	rep(i,1,n)std::cin >> val[i];
	std::memset(cnt,0,sizeof(cnt));
	rep(i,1,n)
		rep(c,0,30)
			if((val[i] >> c) & 1)
				cnt[c]++;
	rep(k,1,n){
		bool flg = true;
		rep(c,0,30)flg = flg && (cnt[c] % k == 0);
		if(flg)std::cout << k << " ";
	}
	std::cout << "\n";
}
void SolveC(){  //Array Elimination
    cin >> N; memset(C, 0, sizeof C);
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=0; i<30; i++){
        for(int j=1; j<=N; j++) if(A[j] & (1 << i)) C[i]++;
    }
    int g = 0;
    for(int i=0; i<30; i++) g = __gcd(g, C[i]);
    for(int i=1; i<=N; i++) if(g % i == 0) cout << i << " ";
    cout << "\n";
}


const int N=5e5+5,D=1e9;
struct Climber{int x,y;}a[N];
bool cmp(Climber a,Climber b){
	return max(a.x,a.y)!=max(b.x,b.y)?max(a.x,a.y)<max(b.x,b.y):a.x<b.x;
}
void solveF(){ //Mountain
int n,d,res=0;
	cin>>n>>d;
	for(int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i) if(a[i].x>=d) d=max(d,a[i].y),res++;
	return printf("%d\n",res),0;
}
/*
哦，整洁度必然是从小到大的，因为可以经过调换使得其从小到大。
*/

bool comp(pair<int,int>& x, pair<int,int>& y){
    int mx = max(x.first,x.second), my = max(y.first,y.second);
    int mnx = min(x.first,x.second), mny = min(y.first,y.second);
    if (mx < my) return true;
    if (my < mx) return false;
    return mnx < mny;
}
void solveFF(){ //Mountain
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,d; cin >> n >> d;
    vector<pair<int,int>> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i].first >> nums[i].second;
    }
    sort(nums.begin(),nums.end(),comp);
    int count = 0;
    for (int i = 0; i < n; i++){
        if (nums[i].first >= d){
            d = max(d,nums[i].second);
            count++;
        }
    }
    cout << count << "\n";
    return ;
}
