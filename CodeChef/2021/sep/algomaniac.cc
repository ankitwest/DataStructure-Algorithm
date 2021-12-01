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

void solve(){
	//saint
	vector<int> a(3),b(3);
	int a1=0,b1=0;
	for(auto &x:a){
		cin>>x;if(x==1)a1++;
	}
	for(auto &x:b){
		cin>>x;if(x==1)b1++;
	}

	if(a1==b1)
		cout<<"Pass"<<endl;
	else
		cout<<"Fail"<<endl;



}

void solve2()  {
	//drugs
        int n,k,l;  cin>>n>>k>>l;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
        	cin>>arr[i];
        }
    	int maxi = *max_element(arr.begin(),arr.end()); 
    	int fr = arr[n-1];

    	int ch = maxi - fr;
    	if(ch>=l){
    		cout<<"No"<<endl;return;
    	} else {
    		if(k<0)cout<<"No"<<endl;
    		else cout<<"Yes"<<endl;
    	}
    }


void solve3() {
	//median
	int k,n;cin>>k>>n;
	vector<int> arr(n);
	for(auto &x:arr)
		cin>>x;

    // int maxi = *max_element(arr.begin(),arr.end()); 

}

void solve4(){
	//rumbling
}

      	

      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);

    int t;  cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i << ": ";

    return 0;
}



// ________________________________________________________

// vector<pair<int,int>> vp(n);

// sort(vect.begin(), vect.end(), sortbysec);

// bool sortbysec( pair<int,int> &a, pair<int,int> &b){
//     return (a.second < b.second);
// }

// vector< vector<int> > vect{{3, 5, 1},{4, 8, 6},{7, 2, 9}};
// bool sortBySecondCol( const vector<int>& v1 , const vector<int>& v2 ) {
// return v1[1] > v2[1];
// }
// sort(vect.begin(),vect.end(),sortBySecondCol);

//  bool comp(int a, int b){
//     int bits_a = cntBits(a), bits_b = cntBits(b);

//     if(bits_a != bits_b)
//     return bits_a < bits_b;

//     return a < b;
// }

// ________________________________________________________

// if ( bianry_search(all(v),number) ) -> return if the no is there or not , sorted vector  
// accumulate(v.begin(),v.end(),sum) -> return the summation of vector

// ________________________________________________________

// #define lb(v,x) lower_bound(v.begin(),v.end(),x) - v.begin();
// #define ub(v,x) upper_bound(v.begin(),v.end(),x) - v.begin();


//  	sort() ; reverse() ;
// 	int maxi = *max_element(v.begin(),v.end()); 
// 	int mini =  *min_element(v.begin(),v.end()); 
// 	int maxi_index = find(v.begin(),v.end(),maxi)- v.begin();

//   	if ( find(all(v),number) != v.end() ) -> returns an iterator 
	
// 	count(v.begin(),v.end(),number) -> to count the occurence of x in vector   


//  	v1.insert(v1.begin() + 2 , { 30, 40, 50, 60 });   
//     v1.insert(v1.begin(), 2, 4);	//v.insert(startingposition,size,value) 
//     			//inserts 4 two times at front

//     v.erase(v.begin()+4);     	//v.erase(position); 
// 	v.erase(v.begin()+2,v.begin()+5);			

// ________________________________________________________
// pair<int,int> p[n];

// Initialize 
//     vector<int> vec = { 10, 20, 30, 40 };
// 	vector<int> vec(v.begin(),v.end());

// 	sort(a.begin(), a.end(), greater<int>());
// 	sort(arr, arr + n, greater<int>());

// 	// [find ice in vector] 
// 	// [maxi mini sort reverse] [Homo Sapiens]  lower_bound upper_bound
