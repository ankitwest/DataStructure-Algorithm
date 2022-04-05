


class Solution2{
public:
    const int mod = 1e9+7;
    vector<vector<long long int>> dp;
    long long int solve(int n,int k){
        if(k>n) return 0;
        if(k==0 or k==n) return 1;
        if(k==1) return n;
        if(k>n-k) return solve(n,n-k);
        
        if(dp[n][k]!=-1)
            return dp[n][k];
            
        long long int ans = (solve(n-1,k-1))%mod + (solve(n-1,k))%mod;
        ans = ans%mod;
        return dp[n][k] = ans;
    }
    int nCr(int n, int r){
        dp.resize(n+1,vector<long long int>(r+1,-1));
        return solve(n,r);
    }
};

class Solution{
public:
const int mod = 1e9+7;
     int nCr(int n, int r){
         vector<long long int> dp(r+1,0);
         dp[0] = 1;
         
         for(int i=1;i<=n;i++){
             for(int j=min(i,r);j>0;j--){
                 dp[j] = (dp[j]%mod + dp[j-1]%mod)%mod;
             }
         }
         return dp[r];
     }
};
