
#include <bits/stdc++.h>
using namespace std;

#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define int long long
#define ll long long
#define debug0(n) cout<<(n)<<" "
#define debug(n) cout<<(n)<<endl
#define debug2(n,y) cout<<(n)<<" "<<(y)<<endl
const int mod = 998244353;


void solveC(){
	int n,k;cin>>n>>k;
	int arr[n];
	rep(i,0,n) cin>>arr[i];

	int pos[60];
	memset(pos,0,sizeof(pos));
	int j=0;
	rep(i,0,n){
		j=0;
		while(arr[i]){
			pos[j++] += arr[i]%k;
			arr[i]/=k;
		}
	}
	int f=-1;
	rep(i,0,60)
		if(pos[i]>1) {f=1;break;}

	if(f==1) cn; else cy;
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

int modinv(int n){return exp(n, mod-2);}

int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int mod_sub(int a, int b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int mod_div(int a, int b) {return (mod_mul(a, modinv(b)) + mod) % mod;}

const int maxx=2e6+1;
int fact[maxx]; int ifact[maxx];
void facto(){
    fact[0] = 1; ifact[0] = 1;
    for (int i = 1; i <= maxx; i++)
        fact[i] = (fact[i - 1] * i) % mod,
        ifact[i] = modinv(fact[i]);
}

int ncr(int n, int r){
	facto();
    if (r > n) return 0;
    if(r==0 || r==n)  return 1;
    if(r==1 || r==n-1) return n;

    return  mod_div(fact[n], mod_mul( (fact[r]),(fact[n-r]) ) );
}

//mCn-1 * (n-2) * 2^n-3 
void solveD(){
	int n,m;cin>>n>>m;
	int ans=0;
	if(n>2)
	 ans = mod_mul(ncr(m,n-1) , mod_mul(n-2,exp(2,n-3)));

	cout<<ans<<endl;
}

int32_t main(){
         ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        freopen("input.txt", "r", stdin);
   int t; cin>>t;
   while(t--){
    solveD();
   }
   return 0;
  
}




