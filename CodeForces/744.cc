//Div 3

#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
#define pi                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpi                  vector<pi>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
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

void solveA(){
        string s;cin>>s;
        int a=0,b=0,c=0;
        int n=s.size();
        rep(i,0,n){
            if(s[i]=='A') a++;
            else if(s[i]=='B') b++;
            else if(s[i]=='C') c++;
        }

        if(a+c==b) cy; else cn;
    
}
void solveE1(){
    int n;cin>>n;
    vi v(n);
    rep(i,0,n) cin>>v[i];

    deque<int> d;
    // rep(i,0,n) d.pb(v[i]);
    d.push_back(v[0]);
    for(int i=1; i<n; i++){
        if(v[i]<d.front()) d.push_front(v[i]);
        else d.push_back(v[i]);
    }
    rep(i,0,n) debug0(d[i]);

    ln;
} 

void iterate(int i,int j,vector<vector<char>>& given,vector<pair<int,int>>& mark){
    int left=j,right=j;
    int down=i;int m=given[0].size();
    while(down>=0 && left>=0 && right<m and given[down][left]=='*' and given[down][right]=='*'){
        mark.pb({down,left});
        mark.pb({down,right});
        left--; right++;
        down--;
    }
}
void solveC(){
    int n,m,k;cin>>n>>m>>k;
    vector<vector<char>> given(n, vector<char>(m));
    vector<vector<char>> obtained(n, vector<char>(m,'.'));

    rep(i,0,n)
        rep(j,0,m)
            cin>>given[i][j];

    rep(i,0,n){
        rep(j,0,m){
        if(given[i][j]!='*') continue;
        vector<pair<int, int>> mark;
        iterate(i,j,given,mark);
        if(mark.size()>= 2*k+2){
            for(auto l:mark)
                obtained[l.ff][l.ss]='*';
        }
        
    }
}
 debug(given==obtained?"YES":"NO");
}


void solveD(){
    int n;cin>>n;
    priority_queue<pair<int,int>> pq;
    rep(i,0,n){
        int a;cin>>a;
        if(a==0)continue;
        pq.push({a,i+1});
    }
    vpi ans;
    while(pq.size()>1){
        pi p =pq.top(); pq.pop();
        pi q =pq.top(); pq.pop();
        p.ff--;q.ff--;
        ans.pb({p.ss,q.ss});
        if(p.ff!=0) pq.push(p);
        if(q.ff!=0) pq.push(q);
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)
        debug2(x.ff,x.ss);

}
void solveD2(){
      int n;cin>>n;
    multiset<pi,greater<pi> > s;
    rep(i,0,n){
        int a;cin>>a;
        if(a==0)continue;
        s.insert({a,i+1});
    }
    vpi ans;
    while(s.size()>1){
        pi p = *s.begin(); s.erase(p);
        pi q = *s.begin(); s.erase(q);
        ans.pb({p.ss,q.ss});
        p.ff--;q.ff--;
        if(p.ff!=0)s.insert(p);
        if(q.ff!=0)s.insert(q);
    }
     cout << ans.size() << '\n';
  for(auto x:ans)
    debug2(x.ff,x.ss);
}

// B is missing and also E2





int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;  cin>>t;
    while(t--) 
       solveA();       // cout << "Case #" << i << ": ";

    return 0;


}

//  void solve() {
//   int n;
//   cin >> n;
//   vi a(n);
//   rep(i,0, n) cin >> a[i];

//   struct An {
//     int l, r, d;
//   };

//   vector<An> ans;

//   rep(i,0, n) {
//     int mini = INT_MAX;
//     int miniIdx = -1;
//     // int maxi =INT_MIN;int maxiIdx = -1;

//     REP(j, i, n) {
//       if (a[j] < mini) mini = a[j], miniIdx = j;
//       // if(a[j]>maxi) maxi = a[j],maxiIdx=j;
//     }

//     if (i == miniIdx) continue;
//     // if (i == maxiIdx) continue;

//     An currAns;

//     currAns.l = i; //i
//     currAns.r = miniIdx; //maxiIdx
//     currAns.d = miniIdx - i; //1

//     int teD = currAns.d;
// // rotation
//     while (teD--) {
//       int te = a[i];
//       REP(j, i, miniIdx) {
//         a[j] = a[j + 1];
//       }

//       a[miniIdx] = te;
//     }

//     ans.pb(currAns);
//   }

//   cout << ans.size() << '\n';
//   rep(i,0, ans.size()) {
//     cout << ans[i].l + 1 << ' ' << ans[i].r + 1 << ' ' << ans[i].d << '\n';
//   }
// }

//  void solve2() {
//   int n;
//   cin >> n;
//   vi a(n);
//   rep(i,0, n) cin >> a[i];

//   struct An {
//     int l, r, d;
//   };

//   vector<An> ans;

//   rep(i,0, n) {
//     // int maxi =INT_MIN;int maxiIdx = -1;

// int maxi = *max_element(a.begin() , a.end()-1);
//    int maxiIdx = max_element(a.begin() , a.end()-1) - a.begin(); 
//     if (i == maxiIdx) continue;

//     An currAns;

//     currAns.l = i+1; 
//     currAns.r =  maxiIdx;
//     currAns.d =  1;

// // rotation
//       int te = a[i];
//       REP(j, i, maxiIdx) {
//         a[j] = a[j + 1];
//       }
//       a[maxiIdx] = te;

//     ans.pb(currAns);
//   }

//   cout << ans.size() << '\n';
//   rep(i,0, ans.size()) 
//     cout << ans[i].l  << ' ' << ans[i].r  << ' ' << ans[i].d << '\n';
  
// }

