// Return the fewest number of coins that you need to make up that amount.
// Min no of coins required to form the coin
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
       int maxi = amt+1;
        vector<int> dp(amt+1,maxi);
        dp[0]=0;  // zero does not require any coin to make 
        
	    // coins must be sorted 
        for(auto coin:coins){
            for(int j=1;j<=amt;j++){
                if(j>=coin)
                    dp[j] = min(dp[j],dp[j-coin]+1);
            }
        }
        
        return dp[amt]>amt?-1:dp[amt];
    }
};



// Return the number of combinations that make up that amount. 

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


// Return the number of permuatations that make up that amount. 

class Solution {
public:
    int combinationSum4(vector<int>& coins, int target) {
        unsigned int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;  // there is only way(either permutaion or combination) to make zero by using no coins
        
        // this is the permutation question 
        for (int i=1;i<=target;i++) {
            for (int coin : coins) {
                if (i >= coin)
                    dp[i] += dp[i-coin];
            }
        }
        return dp[target];
    }
};
