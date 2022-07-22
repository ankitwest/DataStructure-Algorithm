
const int N = 23;
int dp[N][N][N];

int solve(string A, string B, string C, int i, int j, int k){
    if(i<=0 or j<=0 or k<=0) return 0;
    
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    
    int ans = 0;
    if(A[i-1]==B[j-1] and B[j-1]==C[k-1])
        ans = 1 + solve(A,B,C,i-1,j-1,k-1);
    else
        ans = max({solve(A,B,C,i-1,j,k), solve(A,B,C,i,j-1,k), solve(A,B,C,i,j,k-1)});
        
    return dp[i][j][k] = ans;
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    memset(dp,-1,sizeof(dp));
    return solve(A,B,C,n1,n2,n3);
}
