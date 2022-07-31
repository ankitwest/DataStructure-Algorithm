// coin change is of 3 type
// minimum to make that amt
// combination
// permutation



// 0322. Coin Change
// Return the fewest number of coins that you need to make up that amount.
// Min no of coins required to form the coin
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
       int maxi = amt+1;
        vector<int> dp(amt+1,maxi);
        dp[0]=0;  // zero does not require any coin to make 
        
	    // coins must be sorted 
	    // better for each amt we run all possible coin
	for(int j=1;j<=amt;j++){	    
            for(auto coin:coins){
                if(j>=coin)
                    dp[j] = min(dp[j],dp[j-coin]+1);
            }
        }
        
        return dp[amt]>amt?-1:dp[amt];
    }
};


class Solution {
public:
    vector<vector<int>>dp; 
    int solve(int sum,vector<int>& a,int idx)
    {  
        if(sum==0)
            return 0;
        if(idx==1)
        {
            if(sum%a[idx-1]==0)
                return sum/a[idx-1];
            return 1e9;
        }
        
        
        if(dp[sum][idx]!=-1)
         return dp[sum][idx];

        int ans = 0;
        if(sum >= a[idx-1])
            ans = min(1 + solve(sum-a[idx-1],a,idx), solve(sum,a,idx-1));
        else
            ans = solve(sum,a,idx-1);
        
      return dp[sum][idx] = ans;
    }
     int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        dp.resize(amt+1,vector<int>(n+1,-1));
         
        int ans = solve(amt,coins,n);
         if(ans==1000000000) return -1;
         return ans;
    }
};


// 0518. Coin Change 2
// Return the number of combinations that make up that amount. 

class Solution {
public:    //combination
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


class Solution {
public:
    vector<vector<int>>dp;
    int solve(int sum,vector<int>& a,int idx)
    {  
        if(sum==0)
        return 1;
        if(idx==0)
        {
            if(sum%a[idx]==0)
                return 1;
            
            return 0;
        }
        
        
     if(dp[sum][idx]!=-1)
         return dp[sum][idx];
     int take=0;
        if(sum>=a[idx])
            take=solve(sum-a[idx],a,idx);
       int nottake=solve(sum,a,idx-1);
     
     return dp[sum][idx]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
         dp.resize(amount+1,vector<int>(n,-1));
       return  solve(amount,coins,n-1);
    }
};


// 0377. Combination Sum IV
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
Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0
