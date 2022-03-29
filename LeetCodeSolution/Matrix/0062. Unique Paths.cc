      //DP(recursive+memoization)
class Solution {
public:
     int uniquePaths(int m, int n) {
         vector<vector<int>> dp(m,vector<int>(n, 0));
         auto solve = [&dp](auto solve,int i,int j){
             if(i<0 or j<0)
                 return 0;
             if(i==0 and j==0)
                 return 1;
             if(dp[i][j]!=0)
                 return dp[i][j];
             
            int ways = solve(solve,i-1,j) + solve(solve,i,j-1);
             return dp[i][j] = ways;
         };
         return solve(solve,m-1,n-1);
    }
};


class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n, 0));
        for(int i=0;i<m;i++){
             dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
             dp[0][j]=1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};





class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
//                 cout<<cur[j]<<" ";
            }
            cout<<endl;
        }
        return cur[n - 1];
    }
};







Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
