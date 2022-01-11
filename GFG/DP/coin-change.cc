Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.



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
