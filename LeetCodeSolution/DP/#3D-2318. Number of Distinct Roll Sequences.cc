class Solution {
public:
    long long dp[10005][8][8];
    const int mod = 1e9 + 7;
    long long solve(int k,int prev,int prev1){
        if(k==0) 
            return 1;
        if(dp[k][prev][prev1]!=-1)
            return dp[k][prev][prev1];
        
        int ans = 0;
        for(int i=1;i<=6;i++)
        {
            if(__gcd(i,prev) != 1 or prev==i or prev1==i) continue;
            ans += solve(k-1,i,prev)%mod;
            ans %= mod;
        }
        return dp[k][prev][prev1] = ans;
    }
    int distinctSequences(int k) {
        memset(dp,-1,sizeof(dp));
        return solve(k,7,7);
    }
};

The greatest common divisor of any adjacent values in the sequence is equal to 1.
There is at least a gap of 2 rolls between equal valued rolls. More formally, if the value of the ith roll is equal to the value of the jth roll, then abs(i - j) > 2.
  
Input: n = 4
Output: 184
Explanation: Some of the possible sequences are (1, 2, 3, 4), (6, 1, 2, 3), (1, 2, 3, 1), etc.
Some invalid sequences are (1, 2, 1, 3), (1, 2, 3, 6).
(1, 2, 1, 3) is invalid since the first and third roll have an equal value and abs(1 - 3) = 2 (i and j are 1-indexed).
(1, 2, 3, 6) is invalid since the greatest common divisor of 3 and 6 = 3.
There are a total of 184 distinct sequences possible, so we return 184.
