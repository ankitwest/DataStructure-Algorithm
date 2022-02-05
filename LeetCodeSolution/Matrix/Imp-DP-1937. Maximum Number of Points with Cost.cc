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
