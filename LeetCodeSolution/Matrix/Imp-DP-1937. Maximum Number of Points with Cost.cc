//DP

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
        vector<vector<long long>> dp(n,vector<long long> (m,-1));
        
        for(int j=0;j<m;j++){
            dp[0][j] = points[0][j];
        }
        
        for(int i=1;i<n;i++){
            vector<long long> left_dp(m,-1);
            vector<long long> right_dp(m,-1);
            
            left_dp[0] = dp[i-1][0];
            for(int k=1;k<m;k++){
                left_dp[k] = max(left_dp[k-1],dp[i-1][k]+k);
            }
            
            right_dp[m-1] = dp[i-1][m-1]-m+1;
            for(int k=m-2;k>=0;k--){
                right_dp[k] = max(right_dp[k+1],dp[i-1][k]-k);
            }
            
            for(int j=0;j<m;j++){
                dp[i][j] = max(left_dp[j]-j,right_dp[j]+j) + points[i][j];
            }
        }
        
        long long maxi = - 1;
        for(auto x:dp.back()){
            maxi = max(maxi,x);
        }

        return maxi;
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
