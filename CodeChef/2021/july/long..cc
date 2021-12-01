#include <bits/stdc++.h>
using namespace std;

void solve3(){
	//XxOoRr
	//Q3
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int ans =0;
	for(int i=0;i<32;i++){
		int count=0;
		for(int j=0;j<n;j++){
			if(a[j]!=0){
				if(a[j]&1)
					count++;
				a[j]>>=1;
			}
		}
		if(count%k==0)
		ans += count/k;
		else 
		ans += count/k +1;
		//ans +=  (count-1)/k +1; //(count+k-1)/k; 
	}
	cout<<ans<<endl;
}

#define int long long
void solve4(){
	//Optimal Denomination
	//Q4
	int n;
	cin>>n;
	int a[n];
    int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
        sum+=a[i];
	}
    if(n==1){
        cout<<1<<endl; return;
    }
    int prefix[n],suffix[n];
    prefix[0]=a[0];
    suffix[n-1]=a[n-1];
    for(int i=1;i<n;i++){
        prefix[i]=__gcd(prefix[i-1],a[i]);
    }
    for(int i=n-1-1;i>=0;i--){
        suffix[i]=__gcd(suffix[i+1],a[i]);
    }

    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int x = __gcd((i<=0?0:prefix[i-1] ), (i>=n-1?0:suffix[i+1]) );
        ans = min (ans , (sum-a[i])/x + 1ll);
    }
     cout<<ans<<endl;
	
}

int32_t main() {
	int t;cin>>t;
		while(t--){
    	solve();
		}
	return 0;
}
