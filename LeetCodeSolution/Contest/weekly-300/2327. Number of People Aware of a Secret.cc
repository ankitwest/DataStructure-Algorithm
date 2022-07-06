class Solution {
public:
    const int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n,0);
        dp[0] = 1;
        
        int tot = 0;
        for(int i = delay;i<n;i++){
            tot = (tot + dp[i-delay])%mod;
            
            if(i-forget>=0)
                tot = (tot - dp[i-forget] + mod)%mod;
            
            dp[i] = tot;
        }
        
        int ans = 0;
        for(int i = n-forget;i<n;i++){
            ans = (ans + dp[i])%mod;
        }
        return ans % mod;
    }
};


/*
4
1
3
*/
