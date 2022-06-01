
https://practice.geeksforgeeks.org/contest/interview-series-50/problems/#

int minCost(vector<vector<int>> &costs) {
    int n = costs.size(); int k = costs[0].size();
    if(n==0) return 0;
    if(k==0) return 0;
    
    int min1 = INT_MAX; int min2 = INT_MAX;
    int dp[n][k]; memset(dp,0,sizeof(dp));
    
    
    for(int j=0;j<k;j++){
        dp[0][j] = costs[0][j];
        if(dp[0][j] < min1) {
            min2 = min1 ;
            min1 = dp[0][j];
        }else if(dp[0][j] < min2){
            min2 = dp[0][j];
        }
    }
    
    
    
    int cmin1 = INT_MAX; int cmin2 = INT_MAX;
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            
            if(dp[i-1][j] != min1){
                dp[i][j] = min1 + costs[i][j];
            }else {
                dp[i][j] = min2 + costs[i][j];
            }
            
            
            if(dp[i][j] < cmin1){
                 cmin2 = cmin1 ;
                cmin1 = dp[i][j];
            }else if(dp[i][j] < cmin2){
                cmin2 = dp[i][j];
            }
        }
        
        min1 = cmin1;
        min2 = cmin2;
        cmin1 = INT_MAX; 
        cmin2 = INT_MAX;
    }
    
    if(min1<0) return -1;
    
    return min1;
}


Input:
N = 4, K = 3
costs[][] = {{1, 5, 7},
             {5, 8, 4},
             {3, 2, 9},
             {1, 2, 4}}

Output:
8
Explanation:
Paint wall 0 with color 0. Cost = 1
Paint wall 1 with color 2. Cost = 4
Paint wall 2 with color 1. Cost = 2
Paint wall 3 with color 0. Cost = 1
Total Cost = 1 + 4 + 2 + 1 = 8
