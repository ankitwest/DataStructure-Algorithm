int mod = 1e9+7;
#define ll long long 
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<vector<ll>> dp(n,vector<ll>(n));
        dp[0][0]=1; 
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0 or j==i)
                    dp[i][j]=1;
                else
                    dp[i][j] = ((dp[i-1][j-1])%mod + (dp[i-1][j]%mod))%mod;
            }
        }
        vector<ll> ans;
        for(int i=0;i<n;i++){
            ans.push_back(dp[n-1][i]);
        }
        return ans;
    }
};



Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)
