
   
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n, 1));
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};


class Solution {
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
