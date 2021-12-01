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

#define inf INT_MAX
#define ninf INT_MIN
#define int long long
const int mod  =  1e9+7;


void solve4()  {
    //Just a graph
    //Q4
        int n;  cin>>n;
        set<int> s;
        for(int i=0;i<n;i++){
            int wi;
            cin>>wi;
            s.insert(wi-i);
        }
        int l=s.size();
        int ans =(l==1)?n:1;
        cout<<ans<<endl;
}

void solve5(){
        //Crossing Blocks
    int n;cin>>n;
    vector<int> arr(n);
    for(auto &x:arr){
        cin>>x;
    }
    int ans=0;
    int curr=arr[n-1];
    for(int i=n-2;i>0;i--){
        if(arr[i]>curr){
            curr=arr[i];
            ans++;
        }
    }
    if(arr[0]>=curr)
        cout<<ans+1<<endl;
    else
        cout<<-1<<endl;

}

void solve6(){
        ;//
}

void solve7(){
        //Bunny Hops
    
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);

    int t;  cin>>t;
    while(t--) 
       solve5();       // cout << "Case #" << i << ": ";

    return 0;
}
