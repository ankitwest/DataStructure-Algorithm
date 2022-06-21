// similar
class Solution11 {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        int profit = 0;
        int minPrice = INT_MAX;
        for(int i=0;i<n;i++){
            minPrice = min(minPrice,prices[i]);
            profit = max(profit,prices[i]-minPrice);
        }
        return profit;
    }
};


class Solution {
public:
    int f(int ind,int buy,int k,vector<int>& prices,vector<vector<int>>& dp){
        if(ind>=prices.size())
            return 0;
        if(k<=0)
            return 0;
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        int profit = 0;
        if(buy)
            profit = max(-prices[ind] + f(ind+1,!buy,k,prices,dp), 0 + f(ind+1,buy,k,prices,dp) );
        else
            profit = max(+prices[ind] + f(ind+1,!buy,k-1,prices,dp), 0 + f(ind+1,buy,k,prices,dp) );
        
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ind = 0; int buy = 1; int k = 1;
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return f(ind,buy,k,prices,dp);
    }
};

//tabulation
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ind = 0; int buy = 1; int k = 1;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
                    int profit = 0;
                    if(buy)
                        profit = max(-prices[ind] + dp[ind+1][!buy][cap], 0 + dp[ind+1][buy][cap] );
                    else
                        profit = max(+prices[ind] + dp[ind+1][!buy][cap-1], 0 + dp[ind+1][buy][cap] );

                     dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};

// further space optimization
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ind = 0; int buy = 1; int k = 1;
        vector<vector<int>> curr(2, vector<int>(k+1,0)); 
        vector<vector<int>> after(2, vector<int>(k+1,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
                    int profit = 0;
                    if(buy)
                        profit = max(-prices[ind] + after[!buy][cap]    , 0 + after[buy][cap] );
                    else
                        profit = max(+prices[ind] + after[!buy][cap-1]  , 0 + after[buy][cap] );

                    curr[buy][cap] = profit;
                }
                after = curr;
            }
        }
        return curr[1][k];
    }
};





