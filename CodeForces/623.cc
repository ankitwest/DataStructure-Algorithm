//Div 2

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

#define lb(v,x) lower_bound(v.begin(),v.end(),x) - v.begin();
#define ub(v,x) upper_bound(v.begin(),v.end(),x) - v.begin();

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;

void solveC()  {
        int n;  cin>>n;
        vector<int> v(n);
        rep(i,0,n) cin>>v[i];

        set<int> avail;
        REP(i,1,2*n)
        	avail.insert(i);

         vector<int> ans(2*n);

         for(int i=0,k=0;i<2*n;i+=2,k++){
            ans[i]=v[k];
            avail.erase(ans[i]);
         }

         int k=0;
         for(int i=1;i<2*n;i+=2){
            auto x = avail.upper_bound(v[k++]);
            if(x==avail.end()){
                cout<<-1<<endl; return;
            }
            ans[i]= *x; 
            avail.erase(*x);
         }
         tr(x,ans)
            debug0(x);
            ln;

}    


      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solveC();       

    return 0;
}

