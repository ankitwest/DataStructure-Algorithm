class Solution
{
    public:
    long long findMaxSubsetSum(long long A[], int N)
    {
        long long dp[N+1][2];
        for(int i=0;i<=N;i++) dp[i][0] = dp[i][1] = INT_MIN;
        
        dp[0][0] = dp[0][1] = 0;
        // dp[1][0] = 0;  dp[1][1] = A[0];
        // dp[2][0] = A[0]; dp[2][1] = A[1];
        
        for(int i=1;i<=N;i++){
            dp[i][0] = dp[i-1][1] + A[i-1];
            dp[i][1] = max(dp[i-1][1] + A[i-1], dp[i-1][0] );
        }
        
        return max(dp[N][0],dp[N][1]);
    }
};
Input: 
N = 4
A[] = {1,-1,3,4}
Output: 8
Explanation: 
We can choose 1st,3rd and 4th index,
you can check that this is maximum
possible sum. 
