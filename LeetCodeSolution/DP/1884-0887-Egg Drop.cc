
1884. Egg Drop With 2 Eggs and N Floors

class Solution {
public:
    int dp[2+1][1000+1];
    int solve(int egg,int n){
        if(n<=2 or egg==1) return n;
        
        if(dp[egg][n]!=-1)
            return dp[egg][n];
        
        int mini = INT_MAX;
        for(int i=1;i<=n;i++){
            int curr = 1 + max(solve(egg-1,i-1) , solve(egg,n-i));
            mini = min(mini,curr);
        }
        
        return dp[egg][n] = mini;
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(2,n);
    }
};


0887. Super Egg Drop
with n floor and k eggs

class Solution {
public:  // TC: O(n*k*logn) SC: O(n*k)
    vector<vector<int>> dp;
    int solve(int k,int n){
        if(n<=2 or k==1) return n;
        
        if(dp[k][n]!=-1)
            return dp[k][n];
        
        int mini = INT_MAX; int low = 1; int high = n;
        while(low<=high){
            int mid = (low+high)/2;
            int left = solve(k-1,mid-1);
            int right = solve(k,n-mid);
            
            int temp = 1 + max(left,right);
            
            if(left<right)
                low = mid+1;
            else
                high = mid-1;
            
            mini = min(mini,temp);
        }
        return dp[k][n] = mini;
    }
     int superEggDrop(int k, int n) {
         dp.resize(k+1,vector<int> (n+1,-1));
         return solve(k,n);
     }
};
