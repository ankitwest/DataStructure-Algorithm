
class Solution
{
    public:
     vector<vector<int>> dp;
    int solve(int egg,int n){
        if(n<=2) return n;
        if(egg==1) return n;
         
        
        if(dp[egg][n]!=-1)
            return dp[egg][n];
        
        int ans = INT_MAX;
        for(int i=1;i<=n;i++){
            int curr = 1 + max(solve(egg,n-i), solve(egg-1,i-1));
            ans = min(ans, curr);
        }
        
        return dp[egg][n] = ans;
    }
    int eggDrop(int n, int k) 
    {
        int egg = n;
        n = k;

        dp.resize(egg+1,vector<int> (n+1,-1));
        solve(egg,n);
    }
};



//  dp[n][k]

class Solution {
    public:
     vector<vector<int>> dp;
    int solve(int n,int egg){
        if(n==0 or n==1) return n;
        if(egg==1) return n;
         
        
        if(dp[n][egg]!=-1)
            return dp[n][egg];
        
        int ans = INT_MAX;
        for(int i=1;i<=n;i++){  // floor 1 to floor n
            // upper building  n-i floor left
            // lower building  i-1 floor with egg-1
            int curr = 1 + max(solve(n-i,egg), solve(i-1,egg-1));
            ans = min(ans, curr);
        }
        
        return dp[n][egg] = ans;
    }
    int eggDrop(int n, int k) 
    {
        int egg = n;
        n = k;

        dp.resize(n+1,vector<int> (egg+1,-1));
        solve(n,egg);
    }
};
