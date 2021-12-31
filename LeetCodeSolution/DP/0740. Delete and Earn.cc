class Solution {
public:
    int solve(vector<int> sum){
        int n = sum.size();
        int dp[n]; fill(dp,dp+n,0);
        dp[0]=0;
        dp[1]=sum[1];
        
        for(int i=2;i<n;i++){
            dp[i] = max(sum[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
    int deleteAndEarn(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        vector<int> sum(10005,0);
        
        for(int i=0;i<n;i++){
            sum[nums[i]] += nums[i];
        }
        
        vector<int> v(sum.begin(),sum.end());
        return solve(v);
        
    }
};
