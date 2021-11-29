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
 
#define lb(v,x) lower_bound(v.begin(),v.end(),x) - v.begin();
#define ub(v,x) upper_bound(v.begin(),v.end(),x) - v.begin();
#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define all(v)      v.begin(),v.end()
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl

#define int long long
const int mod  =  1e9+7;

bool is_positive(int x){
    return x>0;
}
void solve()  {
    auto sum = [](int x,int y){
        return x+y;
    };

     auto square = [](int i){
        return i * i;
    };
    debug(sum(2,3));

    vector<int> v = {2,3,5};
    debug(all_of(v.begin(),v.end(), [](int x){
        return x>0;
    }));
    debug(all_of(v.begin(),v.end(), is_positive));

    debug(any_of(v.begin(),v.end(), [](int x){
        return x>0;
    }));
    debug(none_of(v.begin(),v.end(), [](int x){
        return x>0;
    }));


     int count_5 = count_if(v.begin(), v.end(), [](int a){
        return (a >= 5);
    });

       int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int f = accumulate(arr, arr + 10, 1, [](int i, int j){
        return i * j;
    });


        auto sol = [](int n){
        return ceil(log2(n));
        };
 
 
     auto sum = [&](long long n) -> long long {
      return (n * n + n) / 2;
    };
 
 
    	auto pro = [](int n) -> int {
   		int x=1;
   		while(n>0){
   			x= x*(n%10);
   			n/=10;
   		}
   		return x;
   	};

}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);
    int t=1; 
     // cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i+1 << ": ";

    return 0;
}
