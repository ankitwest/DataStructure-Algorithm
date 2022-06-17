class Solution {
public:
    int fees ;
    int f(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(ind>=prices.size())
            return 0;
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        int profit = 0;
        if(buy)
            profit = max(-prices[ind] - fees + f(ind+1,!buy,prices,dp), 0 + f(ind+1,buy,prices,dp) );
        else
            profit = max(+prices[ind] + f(ind+1,!buy,prices,dp), 0 + f(ind+1,buy,prices,dp) );
        
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();  fees = fee;
        int ind = 0; int buy = 1;  // int k = inf;
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return f(ind,buy,prices,dp);
    }
};



//tabulation
class Solution2 {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size(); int fees = fee;
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        // dp[n][0] = dp[n][1] = 0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int profit = 0;
                if(buy)
                    profit = max(-prices[ind] - fees + dp[ind+1][!buy], 0 + dp[ind+1][buy] );
                else
                    profit = max(+prices[ind] + dp[ind+1][!buy], 0 + dp[ind+1][buy] );
                
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};


// further space optimization
class Solution3 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2,0); vector<int> after(2,0);
        after[0] = after[1] = 0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int profit = 0;
                if(buy)
                    profit = max(-prices[ind] - fee + after[!buy], 0 + after[buy] );
                else
                    profit = max(+prices[ind] + after[!buy], 0 + after[buy] );
                
                curr[buy] = profit;
            }
            after = curr;
        }
        return curr[1];
    }
};
