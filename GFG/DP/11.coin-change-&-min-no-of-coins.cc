Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.


// Q? coin change	
// combination	

class Solutin{
    long long int count(int coins[], int n, int amt) {
    // trying to keep similar to number of coins problem  // dp[0]=1;
    
    vector<long long int> dp(amt+1,0);   //int was giving negative answer on big tc;
        dp[0]=1;
        sort(coins,coins+n);
        
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amt;j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amt];    
    }  
};


//Q? min coin
// find min no of coins to make up target


 class Solution {   
    public:
	int MinCoin(vector<int>coins, int amt)
	{
	    int maxi = amt+1;
	    vector<int> dp(amt+1,maxi);
	    dp[0]=0;
	    
	    for(auto coin:coins){
	        for(int j=1;j<=amt;j++){
	            if(coin<=j)
	                dp[j] = min(dp[j],1 + dp[j-coin]);
	        }
	    }

	    return dp[amt]>amt?-1:dp[amt];
	}
};

class Solution {
public:    
    int MinCoin(vector<int>coins, int amt){ 
	 int maxi = amt+1;
	vector<int> dp(amt+1,maxi);
	   dp[0] = 0;

	for(int j=1;j<=amt;j++){
	    for(auto coin:coins){
		   if(coin<=j)
		      dp[j] = min(dp[j],1 + dp[j-coin]);
	       }
	    }
	   return dp[amt]>amt?-1:dp[amt];
	} 
};





//Q? Another coin change problem
// make up target from infinite coins but only k coins

class Solution{
public:
  vector<vector<int>> dp;
  int solve(int n,int k,int target,vector<int> &coins){
    if(k==0 and target==0)
        return 1;
    
    if(k<=0 or target<=0)
        return 0;
        
    if(dp[k][target]!=-1)
        return dp[k][target];
        
    bool ans = 0;
    for(int i=0;i<n;i++){
        ans = ans | solve(n,k-1,target-coins[i],coins);
    }
    return dp[k][target] = ans;
  }
  
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
        dp.resize(k+1,vector<int> (target+1,-1));
       return solve(n,k,target,coins);
    }
};


Input:
n = 5, k = 3, target = 11
coins = {1, 10, 5, 8, 6}
Output: 
1

Explanation: 
2 coins of 5 and 1 coins of 1 can be used 
to make change of 11 i.e. 11 => 5+5+1.

	
