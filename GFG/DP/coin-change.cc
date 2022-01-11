Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.



class Solutin{
  long long int count(int coins[], int n, int amt) {
        vector<int> dp(amt+1,0);
        dp[0]=1;
        sort(coins,coins+n);
        for(int i=0;i<n;i++){
            for(int j=1;j<=amt;j++){
                if(j>=coins[i])
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amt];
    }
};
