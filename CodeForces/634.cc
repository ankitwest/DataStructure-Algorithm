//Div 3

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)

#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int lcm(int a, int b){  return a/gcd(a, b)*b; }

#define int long long
const int mod  =  1e9+7;

void solveB()  {
        int n,a,b;  cin>>n>>a>>b;
        string s="";
        for(int i=0;i<n;i+=b){
        	int j=0;
        	while(j<b and s.size()<n){
        		s += j+'a';
        	j++;
        	}
        }
        debug(s);
}

//Anti Suduko
void solveD(){
	vector<string> v;
	for(int i=0;i<9;i++){
		string s;cin>>s;
		v.push_back(s);
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(v[i][j]=='5')
				v[i][j]='2';
		}
	}
	tr(x,v)
	cout<<x<<endl;
}   


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solveD();       

    return 0;
}
