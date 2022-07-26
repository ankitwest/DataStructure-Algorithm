//DP

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(); int m = points[0].size();
        
        vector<vector<long long>> dp(n,vector<long long> (m,-1));
        
        for(int j=0;j<m;j++)
            dp[0][j] = points[0][j];
        
        
        for(int i=1;i<n;i++){
            vector<long long> left_dp(m,-1);
            vector<long long> right_dp(m,-1);
            
            left_dp[0] = dp[i-1][0];
            for(int k=1; k<m; k++){
                left_dp[k] = max(left_dp[k-1], dp[i-1][k] + k);
            }
            
            right_dp[m-1] = dp[i-1][m-1] - m + 1;
            for(int k=m-2; k>=0; k--){
                right_dp[k] = max(right_dp[k+1], dp[i-1][k] - k);
            }
            
            for(int j=0; j<m; j++){
                dp[i][j] = max(left_dp[j] - j, right_dp[j] + j) + points[i][j];
            }
        }
        
        long long maxi = - 1;
        for(auto x: dp.back()){
            maxi = max(maxi, x);
        }

        return maxi;
    }
};


// copied
class Solution {
public:
    long long maxPoints(vector<vector<int>>& P) {
      ll n = P.size(), m = P[0].size();

      vector<ll> prev(m); 
      for(int i=0; i<m; ++i) prev[i] = P[0][i];
      
      for(int i = 1; i < n; ++i){
        vector<ll> curr(m, 0);
        auto right = curr, left = curr;
        
        // traverse left to right
        left[0] = prev[0];
        for(int j=1; j<m; ++j) {
          left[j] = max(left[j-1]-1, prev[j]);
        }
        
        // traverse right to left
        right[m-1] = prev[m-1];
        for(int j=m-2; j>=0; --j) {
          right[j] = max(right[j+1]-1, prev[j]);
        }
        
        // update current with max from left, right + value
        for(int j=0; j<m; ++j){
          curr[j] = P[i][j] + max(left[j], right[j]);
        }
        
        prev = curr;
      }
      
      ll ans = prev[0];
      for(auto &i: prev) ans = max(ans, i);
      return ans;
    }
};


Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
    
    
    
    Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
