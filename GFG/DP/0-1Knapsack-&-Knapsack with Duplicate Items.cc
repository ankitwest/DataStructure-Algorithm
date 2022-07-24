0 - 1 Knapsack Problem

class Solution{
public:
    int knapSack(int W, int wt[], int val[], int N) 
    { 
      int dp[N+1][W+1]; 
      memset(dp,0,sizeof(dp));
        
        for(int i=0; i<=N; i++)
            dp[i][0] = 0;
        for(int w=0; w<=W; w++)
            dp[0][w] = 0;
            
            
        for(int i=1; i<=N; i++){
            for(int w=1; w<=W; w++){  
                if(wt[i-1] <= w)
                    dp[i][w] = max(dp[i-1][w] , dp[i-1][w-wt[i-1]] + val[i-1]);
                else 
                    dp[i][w] = dp[i-1][w];
            }
        }
        
        return dp[N][W];
    }
  };





Knapsack with Duplicate Items

class Solution{
  public:
    int knapSack(int W, int wt[], int val[], int N) 
    { 
       int dp[N+1][W+1];
       memset(dp,-1,sizeof(dp));
       
       for(int i=0; i<=N; i++)
            dp[i][0] = 0;
       for(int w=0; w<=W; w++)
            dp[0][w] = 0;
       
       
       for(int i=1; i<=N; i++){
           for(int w=1; w<=W; w++){
               if(wt[i-1] <= w)
                   dp[i][w] = max( dp[i-1][w] , dp[i][w-wt[i-1]] + val[i-1] );
               else
                   dp[i][w] = dp[i-1][w];
           }
       }
       return dp[N][W];
   }
};
