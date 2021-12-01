#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define all(x)      x.begin(),x.end()

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;


void solve()  {
        int n;  cin>>n;
        if(n%4==0){
        	cy;
   	    	vector<int> a,b;
   		int i=0;int j=0;
			for(i=1;i<=n/4;i++) 	a.pb(i);
   		for(i=n/4+1;i<=n-n/4;i++) b.pb(i);
   		for(j=i;j<=n;j++) a.pb(j);

   		rep(i,0,a.size()) debug0(a[i]);  ln;
   		rep(i,0,b.size()) debug0(b[i]);  ln;

        } else{
        	cn;
        } 
        
}
void solvexx()  {
        int n;  cin>>n;
        if(n%4==0){
        	cy;
   	    	vector<int> a,b;
   		REP(i,1,n/2){
   			if(i%2==1)
   				a.pb(i),b.pb(n-i+1);
   			else
   				b.pb(i),a.pb(n-i+1);
   		}
   		sort(a.begin(),a.end()); 
   		sort(b.begin(),b.end()); 
   		rep(i,0,n/2) debug0(a[i]);  ln;
   		rep(i,0,n/2) debug0(b[i]);  ln;

        } else{
        	cn;
        } 
        
}
// void solve2(){
// 	int l,r;
// 	cin>>l>>r;
// 	int x = l/3;
// 	int y = r/3;

// 	int ans = y-x;
// 	if(l%3==0) ans++;
// 	// if(r%3==0) ans++;
// 	debug(ans);
// 	return;
// }

#define ca cout<<"ALICE"<<endl
#define cb cout<<"BOB"<<endl

#define int long long 
bool win(int n){
	if(n==0) return 0;
	if(n&1) return !win(n-1);
	if(n%4!=0 and n%2==0) return !win(n/2);

	return 1;
}
void solve3(){
	int n;cin>>n;

	if(win(n)) ca; else cb;

	return ;
}
 vector<int> prime_store;
void sieve() {
     int n=1000009;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
 
        for (int p = 2; p * p <= n; p++){
            if (prime[p] == true){
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
       int ctr=0;
        for(int i=2;i<n;i++){
            if(prime[i]==true){
                prime_store.push_back(i); ctr++;
                if(ctr==20) break;
            }
        }
}

void solve4(){
	sieve();
	int n;cin>>n;
	if(n%2==0){
		debug2(2*n,n);
	}else{
		vector<int> primes={3,5,7,11,13,17,19,23,29,31,37,41,43,47,54,59,61,67,71,73}
		for(auto x: primes)
			if(n%x){
				debug2(n*x,n*(x-1));
				break;
			}
	}

}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);

    int t;  cin>>t;
    while(t--) 
       solve4();       // cout << "Case #" << i << ": ";

    return 0;
}
