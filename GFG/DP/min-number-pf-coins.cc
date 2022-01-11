 GFG Solution  
    bettter and simple one 
    
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
