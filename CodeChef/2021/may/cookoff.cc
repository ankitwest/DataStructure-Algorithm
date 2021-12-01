#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=(int)(a); i<(int)(b); i++)



int mat[1001][1001];

void pre()
{
	mat[1][1] = 1;
	rep(i, 1, 1001)
	{
		mat[i][1] = i * (i + 1) / 2;
		rep(j, 2, 1001)
		{
			mat[i][j] = mat[i][j - 1] + j - 1 + i - 1;
		}
	}
	//debug(mat[1][1]);
	// rep(i, 1, 10)
	// {
	// 	rep(j, 1, 10)
	// 	{
	// 		debug0(mat[i][j]);
	// 	}
	// 	ln;
	// }
}

void solve()
{
	//The Last Problem
	//Q1
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	pre();

	int sum = 0;
	int i;
	for (i = x1; i <= x2; i++)
	{
		sum += mat[i][y1];
	}

	for ( i = y1 + 1 ; i <= y2; i++)
	{
		sum += mat[x2][i];

	}
	cout << sum << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t = 1;  cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}
//________________________________________________________________



#include <bits/stdc++.h>
using namespace std;

void solve()
{
	//Chef and Subarray 
	//Q4
	int n; cin >> n;
	int k; cin >> k;
	int a[n];
	map<int, int>m[k];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		// m[a[i] % k]++;
		m[i % k][a[i]]++;
	}

	// for (int i = 0; i < k; i++) {
	// 	for (auto [num, cnt] : m[i])
	// 	{
	// 		//debug2(num, cnt);
	// 	}
	// 	//ln;
	// }

	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		int tot = 0; int maxcnt = -1;
		for (auto [num, cnt] : m[i])
		{
			tot += cnt;
			maxcnt = max(maxcnt, cnt); //maxx = max(maxx,num);
		}
		//debug2(tot, maxcnt);
		ans += tot - maxcnt;
	}
	cout << ans << endl;



}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t = 1;  cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}
