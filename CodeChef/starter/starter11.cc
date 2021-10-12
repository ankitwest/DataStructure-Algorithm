#include <bits/stdc++.h>
using namespace std;

#define all(x)      x.begin(),x.end()

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl


#define int long long


// void so(){
// 	int x;cin>>x;
// 	 x=x%4;

// 	if(x==1)
// 		debug("East");
// 	else if(x==2)
// 		debug("South");
// 	else if(x==3)
// 		debug("West");
// 	else if(x==0)
// 		debug("North");
// }
// void sol(){
// 	int n,s;cin>>n>>s;
// 	if(s<=n){
// 		debug(s);
// 	}else{
// 		int j=0;
// 		for(int i=s;i>=0;i--){
// 			int a=i; int b=j;
// 			if(a==n and (a+b)==s)
// 				debug(a-b);
// 			else
// 				j++;
// 		}
// 	}
// 	return;
// }


// void grid(){
// 	int n; cin>>n;
// 	if(n&1){
// 		for(int i=0;i<n;i++){
// 			for(int j=0;j<n;j++){
// 				if(i==j)
// 					debug0(-1);
// 				else
// 					debug0(1);
// 			}
// 			ln;
// 		}
// 	}else{
// 		for(int i=0;i<n;i++){
// 			for(int j=0;j<n;j++)
// 					debug0(-1);
// 			ln;
// 		}

// 	}

// 	return;
// }



void solv()  {
    ll n,k;
	ll ans;
	    cin >> n >> k;
	    ans = (n * (n + 1)) / 2 - k;
	    if(ans>=1 and ans<=n)
	    cout << ans << endl;
	    else
	    cout << "-1"<<endl;
        
}

      

void pos(){
	int n; cin>>n;int k;cin>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

}
void count(){
	int n;cin>>n;
	vector<int> arr(n-1);
	for(int i=0;i<n-1;i++){
		cin>>arr[i];
	}

	int maxi = *max_element(arr.begin(),arr.end()); 
	int diff = 100000-maxi;
	int ans = 2*diff+1;
	// debug(maxi);
	debug(ans);

}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);

    int t;  cin>>t;
    while(t--) 
      solv();       // cout << "Case #" << i << ": ";

    return 0;
}


// int32_t main(){
// 	    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//     // freopen("input.txt", "r", stdin);
// 	int t;cin >> t;
// 	while(t--){
// 		int n,s;cin>>n>>s;
// 		int sum=n*(n+1)/2;
// 		if(s<sum)
// 			debug(sum-s);
// 		else
// 			debug(-1);
// 	}
// 	return 0;
// }