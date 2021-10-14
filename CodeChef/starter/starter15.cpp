//Div 2

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

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define ll long long
#define int long long
const int mod = 1e9+7;
int pow(int x, int y);

void solveA(){
    int n;cin>>n;
    string s;cin>>s;
    int arr[n];int brr[n];
    memset(arr,0,sizeof(arr));
    memset(brr,0,sizeof(brr));

    rep(i,0,n)  arr[i]=(s[i]-'0')-i;

    rep(i,0,n)  brr[i]=(s[i]-'0')+i;
        
    map<int,int>m1,m2;
    rep(i,0,n){
        m1[arr[i]]++;
    }
    rep(i,0,n){
        m2[brr[i]]++;
    }

    int ans=0;
    for(auto [x,y]:m1){
        if(y>=2){
            ans += (y)*(y-1)/2;
        }
    }

    for(auto [x,y]:m2){
        if(y>=2){
            ans += (y)*(y-1)/2;
        }
    }
    debug(ans);
}


void solveB()  {
        int n,even,odd;  cin>>n>>even>>odd;

        int ans=0;

        if(even==0 and odd==0) {cout<<0<<endl; return; }
        if(even>0 and odd>0){
                    if(n%2==0){
                while(n%2==0){
                    n/=2;ans+=even;
                }
            }
            for(int i=3;i*i<=n;i++){
                if(n%i==0){
                    while(n%i==0){
                        n/=i;ans+=odd;
                    }
                }
            }
            if(n>1) ans+=odd;
        
        }else if(even>0 and odd<0){
          
            int ctr=0;
            if(n%2==0){
                while(n%2==0){
                    n/=2;ctr++;
                }
            }
            ans += even*ctr;
            if (ctr==0) ans += odd;
        }else if(odd>0 and even<0){
            if(n%2==0){
                while(n%2==0){
                    n/=2;
                }
                ans += even;
            }
            for(int i=3;i*i<=n;i++){
                if(n%i==0){
                    while(n%i==0){
                        n/=i;ans+=odd;
                    }
                }
            }
         if(n>1) ans+=odd;
        }else if(odd<0 and even<0){

            if(n%2==0) ans += even;
            else ans += odd;

        } else if(odd==0){

            if(even>0){
                if(n%2==0) {
                while(n%2==0){
                    n/=2;ans += even;
                    }
                }
            } else {
                if(n%2==0) ans += even;
                else ans += odd;
            }

        } else if(even==0){
            if(odd>0){
                if(n%2==0) {
                while(n%2==0){
                    n/=2;
                    }
                }
                for(int i=3;i*i<=n;i++){
                if(n%i==0){
                    while(n%i==0){
                        n/=i;ans+=odd;
                    }
                }
            }
         if(n>1) ans+=odd;
            }else{
                if(n%2==1) ans += odd;
                else ans += even;
            }
        }
       debug(ans);

}

void solveB(){
        ll n;
        ll a, b;
        cin >> n >> a >> b;
        ll w = n;
        ll  even = 0, odd = 0;
        for (ll i = 2; i * i <= n; i++){
            while (n % i == 0){
                if (i % 2 == 0)  even++;
                else odd++;
                n /= i;
            }
        }
        if (n > 1)
        {
            if (n % 2 == 0) even++;
            else odd++;
        }

        ll ans = 0;
        if (a > 0 && b > 0){
            ans += (even*a + odd*b);
        }
        else if (a < 0 && b > 0){
            if(w%2==0) ans=a+odd*b;
            else ans=odd*b;
        }
        else if (a > 0 && b < 0){    
            if(w%2==0) ans = even * a;
            else ans=b+even*a;
        }
        else if (a < 0 && b < 0){
            if ((w % 2LL) == 0)  ans = a;
            else  ans = b;
        }
        else if (a == 0)
        {
            if (b > 0) ans += (odd * b);
            else{
                if (w % 2 == 0) ans = a;
                else ans = b;
            }
        }
        else if (b == 0){
            if (a > 0) ans += (even * a);
            else{
                if (w % 2 == 1) ans = b;
                else ans = a;
            }
        }
        cout << ans << endl;

}
void solveC(){
    int c;cin>>c;
    int k=0;int n=c;
    while(n){
        n=n>>1;
        k++;
    }
    k--;
    if(c==0){
        debug(2);
        debug2(1,1);
        return;
    }
        vector<int> v;
        int xo=0;
            for (int bit = k; bit >= 0; bit--){
                if((xo & (1LL<<bit)) != (c & (1LL<<bit))){
                    // cout<<bit<<" ";
                int n = (1LL<<(bit+1LL));
                xo = xo^(n-1LL);
                v.push_back(n-1LL);
                }
            }
            debug(v.size());
            rep(i,0,v.size()){
                debug0(v[i]);
            }
            ln;

}    
void solveD(){
    int n,l,r;cin>>n>>l>>r;
    vector<int> arr(n);
    rep(i,0,n) cin>>arr[i];
    sort(all(arr));
    int ans =0;
    tr(y,arr){
        int len_y = log10(y)+1;
        int d = pow(10LL,len_y);
        int L = (l-y+d-1LL)/d;
        int R = (r-y)/d;
        ans += upper_bound(all(arr),R)-lower_bound(all(arr),L);
    }
    debug(ans);
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input2.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve();       

    return 0;
}


int pow(int x, int y){
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







