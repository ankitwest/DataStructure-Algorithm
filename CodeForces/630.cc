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

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;

int prime[11]={2,3,5,7,11,13,17,19,23,29,31};
void solveB(){
    int n;cin>>n;
      int arr[n];
      rep(i,0,n)
      cin>>arr[i];
     
      vector<int> v(n,-1);
      int k=1;
      for(auto pr:prime){
          bool flag=false;
          rep(i,0,n){
              if(arr[i]%pr==0 and v[i]==-1) flag=true, v[i]=k;
          }
          if(flag)
          k++;
      }
      cout<<k-1<<endl;

      tr(x,v)
      debug0(x);
      ln;

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solveB();       // cout << "Case #" << i << ": ";

    return 0;
}

