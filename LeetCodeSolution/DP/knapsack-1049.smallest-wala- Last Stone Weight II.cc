

class Solution {
public:  //knapsack
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        int n = stones.size(); int k = sum/2;
        vector<vector<int>> dp(n+1,vector<int> (sum/2+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int j=1;j<=k;j++){
            dp[0][j] = 0;
        }
        
        bool take = false, notTake =false;
        for(int i=1;i<=n;i++){
             for(int j=1;j<=k;j++){
                 if(stones[i-1]<=j)
                     take = dp[i-1][j-stones[i-1]];
                 notTake = dp[i-1][j];
                 dp[i][j] = take or notTake;
             }
        }
        
        int small = INT_MAX;
        for(int i=0;i<=k;i++){
            if(dp[n][i]==true)
                small = min(small, sum - 2*i);
        }
        return small;
    }
};

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
