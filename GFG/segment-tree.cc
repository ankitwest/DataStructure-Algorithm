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
