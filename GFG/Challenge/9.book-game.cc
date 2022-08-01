class Solution {
  public:
    long maxScore(vector<int> points) {
        int n = points.size();
        int dp[n+1] = {0};
        dp[n] = points[n-1]; //
        
        int maxi = dp[n];
        for(int i=n-1;i>=1;i--){  // 1 to n
            if(points[i-1] + i <= n)
            dp[i] = points[i-1] + dp[points[i-1] + i]; 
            else 
            dp[i] = points[i-1];
            
            maxi = max(maxi,dp[i]);
        }
        
        // for(int i=1;i<=n;i++)
        // cout<<dp[i]<<" ";
        // cout<<endl;
        
        return maxi;
    }
};
