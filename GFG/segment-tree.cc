https://codeforces.com/problemset/problem/339/D



#include<bits/stdc++.h>
using namespace::std;

const int N = (1 << 17) + 5;

int n;
int q;
int a[N];
int st[4 * N];
int op[4 * N];

void build(int pos = 1, int l = 1, int r = n){
	if(l == r){
		st[pos] = a[l];
		op[pos] = 1;
		return;
	}
	int mi = (l + r) / 2;
	build(2 * pos, l, mi);
	build(2 * pos + 1, mi + 1, r);
	op[pos] = 1 ^ op[2 * pos];
	if(op[pos]) st[pos] = st[2 * pos] ^ st[2 * pos + 1];
	else st[pos] = st[2 * pos] | st[2 * pos + 1];
}

void update(int x, int y, int pos = 1, int l = 1, int r = n){
	if(l == r){
		st[pos] = y;
		return;
	}
	int mi = (l + r) / 2;
	if(x <= mi) update(x, y, 2 * pos, l, mi);
	else update(x, y, 2 * pos + 1, mi + 1, r);
	if(op[pos]) st[pos] = st[2 * pos] ^ st[2 * pos + 1];
	else st[pos] = st[2 * pos] | st[2 * pos + 1];
}

int main(){
	scanf("%d %d", &n, &q);
	n = 1 << n;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build();
	while(q--){
		int p, b;
		scanf("%d %d", &p, &b);
		update(p, b);
		printf("%d\n", st[1]);
	}
	return 0;
}





// Maximum of two node

#include <bits/stdc++.h>
using namespace std;

int a[1000005],seg[10000005];
void build(int ind,int low,int high){
	if(low==high){
		seg[ind]=a[low];
		return ;
	}
	int mid = (low+high)/2;
	build(2*ind+1,low,high);
	build(2*ind+2,low,high);

	seg[ind]=max(seg[ind+1],seg[2*ind+2]);
}

int query(int ind,int low,int high,int l, int r){
	if(low>=l and high<=r){
		return seg[ind];
	}
	if(high<l or low>r) return INT_MIN;
	int mid = (low + high)/2;
	int left = query(2*ind+1,low,mid,l,r);
	int right = query(2*ind+2,mid+1,high,l,r);
	return max(left,right);
}

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	build(0,0,n-1);
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		cout<<(query(0,0,n-1,l,r))<<endl;
	}
}
