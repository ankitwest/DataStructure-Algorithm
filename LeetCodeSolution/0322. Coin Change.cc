Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
           int Max = amt + 1 ;
        vector<int> dp(amt+1, Max);
        
          dp[0]=0;
      
        for(int i = 1 ; i <= amt; i++){
        for(int j = 0 ; j < coins.size() ; j++){
    		if(i >=coins[j])
    			dp[i]  = min(dp[i],dp[i-coins[j]] +1);
           }
      }
    return dp[amt] > amt ? -1 : dp[amt];
    }
};

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
