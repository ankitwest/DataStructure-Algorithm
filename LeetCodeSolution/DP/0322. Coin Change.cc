Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

	// it is permutation
	
// two ways both crt
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
       int maxi = INT_MAX;  // amt+1
        vector<int> dp(amt+1,maxi);
        dp[0]=0;  // zero does not require any coin to make 
        
	    // coins must be sorted 
        for(int i=1;i<=amt;i++){
            for(auto coin:coins){
                if(i>=coin)
                    dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
        return dp[amt]>amt?-1:dp[amt];
    }
};


class Solution1 {
public:
    int coinChange(vector<int>& coins, int amt) {
       int maxi = amt+1;
        vector<int> dp(amt+1,maxi);
        dp[0]=0;  // zero does not require any coin to make 
        
        for(auto coin:coins){
            for(int j=1;j<=amt;j++){
                if(j>=coin)
                    dp[j] = min(dp[j],dp[j-coin]+1);
            }
        }
        return dp[amt]>amt?-1:dp[amt];
    }
};



Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Input: coins = [2], amount = 3
Output: -1
	
	
	
    
    
    GFG Solution  
    bettter and simple one   same
    
 class Solution {   
    public:
	int minCoins(int coins[], int n, int amt) 
	{ 
	   int maxi = amt+1;

	   vector<int> dp(amt+1,maxi);
	   dp[0] = 0;
	   
	   sort(coins,coins+n);
	   
	   for(int i=0;i<n;i++){
	       for(int j=coins[i];j<=amt;j++){
	           dp[j] = min(dp[j],1+dp[j-coins[i]]);
	       }
	   }
	   return dp[amt]>amt?-1:dp[amt];
	} 
    };




Coin Change 2 
	// it is combination
	
	class Solution {
public:
    int change(int amt, vector<int>& coins) {
        vector<int> dp(amt+1,0);
        dp[0]=1; // 1 here represent a way to make it (make zero using no coins)
        
        for(auto coin:coins){
            for(int j=1;j<=amt;j++){
                if(j>=coin)
                    dp[j] += dp[j-coin]; 
            }
        }
        return dp[amt];
    }
};
	
