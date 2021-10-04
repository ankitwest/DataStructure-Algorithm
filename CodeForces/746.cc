#include <bits/stdc++.h>
using namespace std;

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



#define int long long



void solve()  {
        int n,h;  cin>>n>>h;
        vector<int> v(n);
        rep(i,0,n) cin>>v[i];

        sort(all(v));
        reverse(all(v));
        int a=v[0],b=v[1];

        int ans = h/(a+b);
        ans*=2;

        int left = h%(a+b);

        int ctr=0;
        while(left){
        	left=left-a;ctr++;
        	if(left>0){
        		left=left-b;	ctr++;
        		if(left<=0)break;
        	}
        	else break;
        }
        cout<<(ctr+ans)<<endl;
        
}
void solveB(){
        int n,x;  cin>>n>>x;
        vector<int> v(n),s(n);
        rep(i,0,n) cin>>v[i],s[i]=v[i];

        sort(all(s));

        int f=0;
        for(int i=0;i<n;i++){
        	if(s[i]!=v[i]){
        		if(i-x>=0 or i+x<n) continue;
        		else { f=1;break;}
        	}
  
        }
        if(f) cn; else cy;
}  
      	

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solveB();       

    return 0;
}
