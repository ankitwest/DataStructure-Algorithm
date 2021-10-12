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

#define all(x)  x.begin(), x.end()
#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

#define inf INT_MAX
#define ninf INT_MIN
#define int long long
const int mod  =  1e9+7;


void solve()  {
    //Q3
    //team formation
        int n;  cin>>n;
        

        string s,t;
        cin>>s;cin>>t;

        int s1=count(s.begin(), s.end(),'1');
        int t1=count(t.begin(), t.end(),'1');

        int ans = min(s1,t1);
        ans = min(ans , n/2);

        cout<<ans<<endl;

}

void solve2(){
    //Q4
    //diff string
	int n;lscn(n);
	vector<string> str(n);
		

	for(auto &x:str)
		cin>>x;

	string ans ="";
	for(int i=0;i<n;i++){
		if(str[i][i]=='0')
			ans+='1';
		else 
			ans += '0';
	}
	cout<<ans<<endl;
}
  

void solve6()  {
    //Q5
    //Chef and Closure 
    //Incomplete
    
        int n;  cin>>n;
        vector<int> v(n);
        map<int,int> mp;
        for(auto &x:v){
        	cin>>x;
        	mp[x]++;
        }
     
        int opsize=pow(2,n);
        int flag =0;
        for(int counter=0;counter<opsize ;counter++){
        	vector<int> v1;
        	for(int j=0;j<n;j++){
        		if(counter&(1<<j)){
        			v1.push_back(v[j]);
        		}
        	}
        	int l=v1.size();
        	int pro=1;
        	for(int i=0;i<l;i++)
        		pro*=v1[i];

        	if(find(v.begin(),v.end(),pro)==v.end())
        		flag=1;
        	else
        		flag=0;

        }
        flag==1?debug(0):debug(1);



}    

void solve5(){
    //Q6
    //Clear the array
    //Incomplete

	int n,k,x;
	cin>>n>>k>>x;

	vector<int> arr(n);
	for(auto &x:arr)
		cin>>x;

	sort(all(arr),greater<int>());

	     for(intl i = 2*k; i < n ; ++i)
            sum += v[i];

        for(intl i = 0; i < 2*k; i += 2){
            if(v[i] + v[i+1] < x)
                sum += v[i] + v[i+1];
            else
                sum += x;
        }

        cout<<sum<<endl;

}
int32_t main(){
	    
    int t;  cin>>t;
    while(t--) 
       solve5();     // cout << "Case #" << i << ": ";

    return 0;
}
