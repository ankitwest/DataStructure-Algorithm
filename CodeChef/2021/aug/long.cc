#include <bits/stdc++.h>
using namespace std;

void solve2(){
	//Problem Difficulties
	//Q2
	int n=4;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    if(v[0]==v[1] and v[1]==v[2] and v[2]==v[3]){
        cout<<"0"<<endl;
    }
    else if((v[0]==v[1] and v[1]==v[2]) or (v[1]==v[2] and v[2]==v[3])){
        cout<<"1"<<endl;
    }
    else if((v[0]==v[1]) or (v[1]==v[2]) or (v[2]==v[3])){
             cout<<"2"<<endl;
    }
    else if(v[0]!=v[1] and v[1]!=v[2] and v[2]!=v[3]){
             cout<<"2"<<endl;
    }
}


#define int long long
void solve3(){
	//Chef and Bulb Invention
	//Q3
	int n,p,k;cin>>n>>p>>k; //10 4 5
	int x = p%k;
	int y = (n-1) - (n-1)/k*k;

	int ans =0;

	if(x>y){
		ans = (n-1)/k*x + y + 1;
	}
	else{
		ans = ((n-1)/k + 1)*x;
	}
	for(int i=x;i<n;i+=k){
			ans++;
		if(i==p){
			break;
		}
	}
	cout<<ans<<endl;
}

void solve4(){
	//Special Triplets
	//Q4
	int n;cin>>n;
	int ctr=0;
	for(int c=1;c<=n;c++){
		for(int b=c;b<=n;b+=c){
			for(int a=c;a<=n;a+=b){
				if((a%b==c) and (b%c==0))
					ctr++;
				}
		}
	}
	cout<<ctr<<endl;
	
}


int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

	int t=1;  cin>>t;
	while(t--)
		solve();
	return 0;
}
