vector<long long> dp;
    const long long mod = 1e9+7;
    long long solve(int n){
        if(n==0) return 1; //product case
        if(n==1) return 1;
        
        if(dp[n]!=-1)
            return dp[n];
            
        long long ans = 0; //single or pair
        ans = 1LL*solve(n-1)%mod + (n-1)*1LL*solve(n-2)%mod;
        return dp[n] = ans%mod;
    }
public:
    int countFriendsPairings(int n) { 
        dp.resize(n+1,-1);
        return solve(n);
    }
