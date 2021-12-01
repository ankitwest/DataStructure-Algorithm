#include <bits/stdc++.h>
using namespace std;

// Div 2
#define all(n)      n.begin(),n.end()
#define ln cout<<"\n";
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define debug0(n) cout<<(n)<<" "
#define debug(n) cout<<(n)<<endl
#define debug2(n,y) cout<<(n)<<" "<<(y)<<endl

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define tr(n,v)         for(auto &n:v)
#define tr2(n,y,m)      for(auto &[n,y]:m)

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;

int exp(int n, int y){
    int res = 1;
    n = n % mod;
    while (y) {
        if(y & 1) {
            res = (res * n) % mod;
        }
        n = (n * n) % mod;
        y = y>>1;
    }
    return res;
}

int modinv(int n){return exp(n, mod-2);}

int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int mod_sub(int a, int b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int mod_div(int a, int b) {return (mod_mul(a, modinv(b)) + mod) % mod;}

void solveA()  {
        int n;  cin>>n;
        int ans=0;
        if(n==1) ans=1;
        else if(n==2) ans=1;
        else if(n==3) ans=2;
        else if(n==4) ans=2;
        else {
        	if( floor(log2(n))==ceil(log2(n)) ){
        		ans = n-pow(2,floor(log2(n-1)));
        	}else {
        		ans = n-pow(2,floor(log2(n-1)))+1;
        		int maxi = pow(2,floor(log2(n-1)))/2;
        		ans = max(ans,maxi);
        	}
        }
        debug(ans);

}
//3 xor=3 ans=4
//4  xor=3 ans=4
//5  xor=3 ans=4

//7 xor =7 ans=8
// 8  ans =8 xor =7

//14 xor=7 ans=8
// 15 xor=15 ans =16
// 16 xor=15 ans=16 
void solveB(){
	int n;cin>>n;
    int ans=0;
    if(n==0) ans=1;
    else if(n==1) ans=2;
    else if(n==2) ans=2;
    else if(n==5) ans=4;
    else {
    	if( floor(log2(n))==ceil(log2(n)) ){
        		ans=n;
       	}else if( floor(log2(n+1))==ceil(log2(n+1)) ){
       		ans =n+1;
       	}else {
       		// if(n==14) cout<<-1<<endl;
       		int x = pow(2,floor(log2(n-1)));
       		ans = x;
       	}
    }
    debug(ans);
}   

void solveC(){
	int n;cin >> n;
	int d;cin>>d;
	int no=n;
	int pos=0; int ans=0;
	while(no){
		int ld = no%10;
		pos++;
		no/=10;
		if(ld==d){
			no = no*pow(10,pos);
			no += (ld+1)*pow(10,pos-1);
			ans = no-n;
			pos=0;
		}
	}debug(ans);

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solveB();       

    return 0;
}
