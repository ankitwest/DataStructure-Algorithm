

class Solution {
public:

	public:
	int findWinner(int n, int x, int y) {
		// Your code goes here
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		for(int i = 2; i <= n; ++i) {
		    if(i - 1 >= 0) dp[i] = dp[i - 1] ? 0 : 1;
		    if(i - x >= 0) dp[i] |= dp[i - x] ? 0 : 1;
		    if(i - y >= 0) dp[i] |= dp[i - y] ? 0 : 1;
		}
	    return dp[n];
	}
};
Input: N = 5, X = 3, Y = 4
Output: 1
