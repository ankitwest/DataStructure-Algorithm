Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
           int Max = amt + 1;
        vector<int> dp(amt+1, Max);
         dp[0]=0;
        
        for(int val=1;val<=amt;val++){
         for(auto coin:coins){
    		if(val >=coin)
    			dp[val]  = min(dp[val],dp[val-coin]+1);
           }
      }
    return dp[amt] > amt ? -1 : dp[amt];
    }
};

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
