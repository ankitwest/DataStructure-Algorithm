Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.


class Solution {
public:
    int change(int amt, vector<int>& coins) {
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;   // 1 here represent a way to make it (make zero using no coins)
        
        for(auto coin:coins){
            for(int val=1;val<=amt;val++){
                if(val>=coin) 
                    dp[val]+=dp[val-coin];
            }
        }
        return dp[amt];
    }
};

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
