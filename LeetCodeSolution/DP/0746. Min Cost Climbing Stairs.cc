class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1,0);  // top of the floor is n
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <=n ; i++) {
            int jumpOneStep = dp[i - 1] + cost[i - 1];  
            int jumpTwoStep = dp[i - 2] + cost[i - 2];  
            dp[i] = min(jumpOneStep, jumpTwoStep);
        }
        return dp[n];
    }
};


class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=2;i<cost.size();i++){
            cost[i] += min(cost[i-1],cost[i-2]);
        }
        return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
};
