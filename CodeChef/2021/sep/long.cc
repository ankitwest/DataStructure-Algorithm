#include <bits/stdc++.h>
using namespace std;

#define setbits(x) __builtin_popcountll(x)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >

#define precision(n) fixed<<setprecision(n)
#define setprecision(n,ans) cout << fixed << setprecision(9) << ans<<endl

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define rep(i,a,b) for(int i=a;i<b;++i)
#define lscn(n) scanf("%lld", &n)
#define scn(n) scanf("%d", &n)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define debug3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl

#define inf INT_MAX
#define ninf INT_MIN
#define int long long
const int mod  =  1e9+7;


void solveA()  {
        vector<int> v(3);

        for(int i=0;i<3;i++)
        	cin>>v[i];
        int d,e;cin>>d>>e;

        sort(v.begin(),v.end());

        if(v[2]<=e){
        	if(v[1]+v[0]<=d)
        		cout<<"YES"<<endl;
        	else cout<<"NO"<<endl;
        }
        else if (v[1]<=e){
        	if(v[0]+v[2]<=d)
        		cout<<"YES"<<endl;
        	else cout<<"NO"<<endl;
        } 

        else if(v[0]<=e){
        	if(v[1]+v[2]<=d) cout<<"YES"<<endl;
        	 else cout<<"NO"<<endl;
        } 
        else 
        cout<<"NO"<<endl;

}

void solveB(){
	int n,a,b;cin>>n>>a>>b;
	string s;cin>>s;
	int x=0,y=0;
	for(auto i:s)
		if(i=='0') x++;
		else y++;

	int ans = (x*a)+(y*b);
	cout<<ans<<endl;
}
      
void solveC(){
	int n;cin>>n;
	vector<int> v(n);
	for(auto &x:v)
		cin>>x;

	int ev=0,od=0;
	for(auto x:v)
		if(x%2==0) ev++;
	   	 else od++;
	   	 int oddpos=0,evenpos=0;
		oddpos=(n+1)/2;
		 evenpos=(n)/2;
		 int ans = min(evenpos,od)+min(oddpos,ev);
	cout<<ans<<endl;
}

void solveD(){
	int n,x;cin>>n>>x;
	vector<int> v(n);
	for(auto &x:v)
		cin>>x;

	map<int,int> mp,mp2;
	for(int i=0;i<n;i++){
		mp[v[i]]++;
	}

	for(int i=0;i<n;i++){
		mp2[v[i]^x]++;
	}
	int maxi = 0;
	int mini = 1e18;


	for(int i=0;i<n;i++){
		int x = mp[v[i]] + mp2[v[i]];
		int y = mp2[v[i]];

		if(x+y>=maxi and y<mini){
			maxi = x;
			mini = y;
		}
	}
	cout<<maxi<<' '<<mini<<endl;
}


void solveE(){
	int n;cin>>n;
	vector<int> x(n),y(n);
	for(auto &a:x)
		cin>>a;
	for(auto &a:y)
		cin>>a;

	vector<pair<int,int>> vp(n);
	for(int i=0;i<n;i++){
		vp[i]={x[i],y[i]};
		// debug2(vp[i].first,vp[i].second);
	}
	int k=-1;
	for(int i=0;i<n;i++){
		if(x[i]==y[i])
			k=i;
	}
	int ans =0;
	// if(k!=-1){
		for(int i=0;i<n;i++){
			if(k==i)continue;
			else{
				if(abs(x[i]-x[k])==abs(y[i]-y[k]))
					ans++;
				else{
					if(abs(x[i]-x[k])==0 or abs(y[i]-y[k])==0)
						ans++;
					else
					ans+=2;
				}
		cout<<ans<<endl;

			}
		}
	// } else {

	// }
		ln;

}


void solveG(){
	//Coavxin
	int n;cin>>n;
	int x,a,b,c,d;cin>>x>>a>>b>>c>>d;
	int p,q,r,s,t,m;cin>>p>>q>>r>>s>>t>>m;
	int ans =0; int n1=n;
	while(n1--){
		if(n1<n-1){
	 a = (a + ans*t)%m + p;
	 b = (b + ans*t)%m + p;
	 c = (c + ans*t)%m + p;
	 d = (d + ans*t)%m + p;
	}


	int x1=x;
	int i=0;
	while(x1>0){
		i++;
		int cx= a+(i-1)*b;
		x1-=cx;
	}
	x1=x;int j=0;
	while(x1>0){
		j++;
		int cv= c+(j-1)*d;
		x1-=cv;
	}
	x1=x;int k=0,l=0;
	while(x1>0){
		k++;l++;
		int cx= a+(k-1)*b;
		int cv= c+(l-1)*d;
		x1 = x1- cx-cv;
	}
	 ans = max({i-1,j-1,k+l-2});
	 // debug3(i-1,j-1,k+l-2);
	cout<<ans<<endl;
	}
}	


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);

    int t;  cin>>t;
    while(t--) 
       solveD();       // cout << "Case #" << i << ": ";

    return 0;
}
