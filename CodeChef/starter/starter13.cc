#include <bits/stdc++.h>
using namespace std;

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
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;
//Div 3
void solve1(){
	int m,n,k;cin>>m>>n>>k;
	if(n*k<m) cy; else cn;
}
void solve2(){
	int n,p,x,y;cin>>n>>p>>x>>y; //x->child
	int arr[n];
	rep(i,0,n) cin>>arr[i];
	int child=0,adult=0; int ans =0;
	rep(i,0,n){
		if(arr[i]==0) child++; 
		else adult++;
		if(i+1==p) break;
	}

	debug(child*x+adult*y);
}
void solve3()  {
	//Diwali
        int price , a,b,c,x,y;cin>>price>>a>>b>>c>>x>>y;
        int cAnar = b + a*x;
        int cChakri = c + a*y;
        // debug2(cAnar,cChakri);
       int minn = min(cAnar,cChakri);
       int maxx = price/minn;
       debug(maxx);
}

void solve4(){
	//doors
	string s;cin>>s;
	int n = s.size();
	int ctr=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			while(s[i]=='0') i++;
			ctr++;
		}
	}
	int ans =0;
	if(s[0]=='0' and s[n-1]=='0' ) ans = ctr+ctr-1;
	if(s[0]=='0' and s[n-1]=='1' ) ans = ctr+ctr;
	if(s[0]=='1' and s[n-1]=='0' ) ans = ctr+ctr-1;
	if(s[0]=='1' and s[n-1]=='1' and ctr>0 ) ans = ctr+ctr;

	 debug(ans);
	

}

vector<int> factors(int a){
	vector<int> v;

	if(a%2==0){
		v.push_back(2);
		while(a%2==0) a/=2;
			
	}
	for(int i=3;i*i<=a;i+=2){
		if(a%i==0){
			v.push_back(i);
			while(a%i==0) a/=i;
			
		}
	}
	if(a>1) v.push_back(a);

	return v;
}
void solve5(){
	//Add and Divide
	int a,b;cin>>a>>b;

	while(gcd(a,b)>1){
		a /= gcd(a,b);
	}
	if(a==1) cy; else cn;
}

void solve6(){
	//Make array
	int n;cin>>n;
	int A=0,B=0;
	REP(i,1,n) {int x=0 ; cin>>x , A += x*i;}
	REP(i,1,n) {int x=0 ; cin>>x , B += x*i;}

	cout<<B-A<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    // int t2;
    // t2 = clock();
    int t;  cin>>t;
    while(t--) 
       solve6();       // cout << "Case #" << i << ": ";
    // t2 = clock() - t2;
// cout<< "Done in " << t2 / CLOCKS_PER_SEC <<"sec"<< endl;


    return 0;
}

