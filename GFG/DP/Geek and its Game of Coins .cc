We can observe that A wins game for n coins only when B loses for coins n-1 or n-x or n-y. 

	
class Solution {
public:

		public:
	int findWinner(int n, int x, int y) {
		// Your code goes here
		vector<int> dp(n + 1,0);
		dp[0] = false;
		dp[1] = true;
		for(int i = 2; i <= n; ++i) {
		    if(i-1 >= 0 and dp[i-1]==false) 
		        dp[i] = true;
		    else if(i-x >= 0 and dp[i-x]==false) 
		        dp[i] = true;
		    else if(i-y >= 0 and dp[i-y]==false) 
		        dp[i] = true;
		    else 
		        dp[i] = false;
		}
	    return dp[n];
	}

};
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
