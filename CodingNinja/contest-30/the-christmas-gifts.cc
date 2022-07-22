const int mod = 1e9+7;
int solve(int ind,int k,vector<vector<int>> &dp,vector <int>& arr,int n){
    if(k==0) {
//         cout<<ind<<" ";
        return 1;
    }
    if(k<0) return 0;
    
    if(ind==n-1) {
     if(k<=arr[ind])
         return 1;
        return 0;
    }
    if(dp[ind][k]!=-1)
        return dp[ind][k];
    
    
    int t=0;
    for(int i=0;i<=arr[ind];i++){
    //cout<<i<<" "<<k-i<<" "<<ind<<" "<<t<<endl;
        if(k>=i)
        t = (t%mod + solve(ind+1,k-i,dp,arr,n)%mod)%mod;
        
    }
    
    return dp[ind][k] = t%mod;
}
int waysToDistribute(int n, int k , vector < int > arr) {
vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
//     solve(0,k,dp,arr,n);
//     for(int j=0;j<n;j++){
//          for(int i=0;i<k;i++){
//             cout<<dp[j][i]<<" ";
//         }
//         cout<<endl;
//     }
    
    return solve(0,k,dp,arr,n)%mod;
}




partial crrt 
tle
approach 1

    https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-30/5563209/problems/17345?leftPanelTab=0
