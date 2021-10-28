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

void solveA(){
    int x1,y1,x2,y2,x3,y3;cin>>x1>>y1>>x2>>y2>>x3>>y3;

    int ans =-1;
    if(x1==x2 and x2==x3){
        if(y3>min(y1,y2) and y3<max(y1,y2)) ans = abs(x2-x1)+abs(y2-y1)+2;
        else ans = abs(x2-x1)+abs(y2-y1);
    }else if(y1==y2 and y2==y3){
        if(x3>min(x1,x2) and x3<max(x1,x2)) ans = abs(x2-x1)+abs(y2-y1)+2;
        else ans = abs(x2-x1)+abs(y2-y1);
     }else{
        ans = abs(x2-x1)+abs(y2-y1);
     }
     debug(ans);
}
void solveB()  {
       string s;cin>>s; string str = s;
       int n = s.size();

       sort(all(str));

       char ch = 'a';
       rep(i,0,n){
        if(str[i]!=ch++) 
            {cn; return;}
       }

       // checking the latest addition of characters
       int l = 0 , r = n-1 ,ctr=1;
       bool flag = true;
        while(ctr<=n){
            if(s[l]==str[n-ctr])
                l++,ctr++;
            else if(s[r]==str[n-ctr])
                r--,ctr++;
            else
                { flag=false; break; }
        }

        if(flag) cy; else cn;
}


void solveD(){
    int n;cin>>n;
    vi x(n);
    rep(i,0,n) cin>>x[i];
    vi y(n);
    y[0]=0;
    
  //3 methods
    rep(i,1,n){
        y[i]=x[i-1]&(x[i-1]^x[i]);
        x[i]^=y[i];
    }

    for (int i = 1; i < n; i++) {
         int submask = x[i - 1] ^ y[i - 1];
            for (int j = 0; j < 30; j++) {
                if (submask & 1 << j) {
                    if ((x[i] & 1 << j)) {
                        continue;
                    }else{
                        y[i] = y[i] | 1 << j;
                    }
                }
            }
        }

    for(int i = 1;i < n;i++){
            int a = x[i - 1] xor y[i - 1];
            y[i] =  a & (~x[i]);
    }
    
    for(int i=1;i<n;i++){
            int a=x[i-1]^y[i-1];
            // int k = (a&x[i])^(a);
            int k = a&(x[i]^a);
            y[i]=k;
    }

    rep(i,0,n)
        debug0(y[i]);

    ln;
    
    

    // debug(11&(-14));
    // debug(14&(~14));
    // debug(~4);

}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hey.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solveD();       // cout << "Case #" << i+1 << ": ";

    return 0;
}
