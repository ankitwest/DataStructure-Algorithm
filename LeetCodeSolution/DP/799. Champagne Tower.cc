class Solution {
public:
    double champagneTower(int poured, int qr, int qg) {
        vector<vector<double>> dp(101,vector<double>(101,0.0));
        
        dp[0][0] = poured;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]>1){
                    dp[i+1][j] += (dp[i][j]-1)/2.0;
                    dp[i+1][j+1] += (dp[i][j]-1)/2.0;
                    dp[i][j] = 1;
                }
            }
        }
        return dp[qr][qg];
    }
};

Example 1:

Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.
Example 2:

Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.
Example 3:

Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000
