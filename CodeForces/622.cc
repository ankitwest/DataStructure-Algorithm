
//622 Div 2
//A

#include <bits/stdc++.h>
using namespace std;
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define ln cout<<"\n";
#define all(x)      x.begin(),x.end()
#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)

void solveA(){
   int a,b,c;cin>>a>>b>>c;
   int temp=0;
   if(b>a and b>c){
      temp = a; 
      a=b; 
      b=temp;
   }
   else if(c>a and c>b){
      temp = a; 
      a=c;
      c=temp; 
   }
   int k=0;
   if(a)k++,a--;
   if(b)k++,b--;
   if(c)k++,c--;
   if(a and b)k++,a--,b--;
   if(a and c)k++,a--,c--;
   if(b and c)k++,b--,c--;
   if(a and b and c)k++,a--,b--,c--;
   cout<<k<<endl;
}


int main(){
	    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solve();       

    return 0;
}
