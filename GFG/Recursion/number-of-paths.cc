long long numberOfPaths(int m,int m){
    if(m==1 or n==1) return 1;
  
    return numberOfPaths(m-1,n)+numberOfPaths(m,n-1);
}

Expected Time Complexity: O(m + n - 1))
Expected Auxiliary Space: O(1)
  
  
  
  
  long long numberOfPaths(int m,int n){
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0) dp[i][j]=1;
            else if(j==0) dp[i][j]=1;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
