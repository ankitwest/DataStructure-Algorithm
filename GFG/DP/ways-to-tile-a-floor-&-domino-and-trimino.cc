class Solution{
    public:
    long long mod = 1e9+7;
    long long numberOfWays(long long n) {
       int dp[n+1];
    //   memset(dp,0,n+1);
       dp[1]=1;
       dp[2]=2;
       for(int i=3;i<=n;i++) 
        dp[i]=(dp[i-1]+dp[i-2])%mod;
        
        return dp[n];
    }
};



class Solution {
public:
    int numTilings(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int mod = 1e9+7;
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=( (2*dp[i-1])%mod + dp[i-3] )%mod;
        }
        return dp[n];
    }
};
