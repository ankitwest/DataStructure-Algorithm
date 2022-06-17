class Solution {
public:
    int f(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(ind>=prices.size())
            return 0;
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        int profit = 0;
        if(buy)
            profit = max(-prices[ind] + f(ind+1,!buy,prices,dp), 0 + f(ind+1,buy,prices,dp) );
        else
            profit = max(+prices[ind] + f(ind+2,!buy,prices,dp), 0 + f(ind+1,buy,prices,dp) );
        
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ind = 0; int buy = 1;  // int k = inf;
        vector<vector<int>> dp(n+2,vector<int> (2,-1));
        return f(ind,buy,prices,dp);
    }
};


//tabulation
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        // dp[n][0] = dp[n][1] = 0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int profit = 0;
                if(buy)
                    profit = max(-prices[ind] + dp[ind+1][!buy], 0 + dp[ind+1][buy] );
                else
                    profit = max(+prices[ind] + dp[ind+2][!buy], 0 + dp[ind+1][buy] );
                
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};


// further space optimization
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2,0); vector<int> front1(2,0);vector<int> front2(2,0); 
        // front1[0] = front1[1] = 0; 
        // front2[0] = front2[1] = 0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int profit = 0;
                if(buy)
                    profit = max(-prices[ind] + front1[!buy], 0 + front1[buy] );
                else
                    profit = max(+prices[ind] + front2[!buy], 0 + front1[buy] );
                
                curr[buy] = profit;
            }
            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
};
