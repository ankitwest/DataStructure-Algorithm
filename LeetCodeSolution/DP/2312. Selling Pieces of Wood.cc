class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(n+1,vector<long long> (m+1,0));
        
        for(auto v : prices){
            dp[v[0]][v[1]] = v[2];
        }
        
        for(int row=1; row <= n; row++){
            for(int col=1; col <= m; col++){
                for(int i=1; i <= row/2; i++)  //row_cut
                    dp[row][col] = max(dp[row][col] , dp[i][col] + dp[row-i][col]);
                for(int j=1; j <= col/2; j++)  //col_cut
                    dp[row][col] = max(dp[row][col] , dp[row][j] + dp[row][col-j]);
            }
        }
        return dp[n][m];
    }
};
Input: m = 3, n = 5, prices = [[1,4,2],[2,2,7],[2,1,3]]
Output: 19
Explanation: The diagram above shows a possible scenario. It consists of:
- 2 pieces of wood shaped 2 x 2, selling for a price of 2 * 7 = 14.
- 1 piece of wood shaped 2 x 1, selling for a price of 1 * 3 = 3.
- 1 piece of wood shaped 1 x 4, selling for a price of 1 * 2 = 2.
This obtains a total of 14 + 3 + 2 = 19 money earned.
It can be shown that 19 is the maximum amount of money that can be earned.
