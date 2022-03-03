class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int x=0,y=0,z=0;
        for(int i=1;i<n;i++){
            dp[i] = min({2*dp[x],3*dp[y],5*dp[z]});
            
            if(dp[i]==2*dp[x]) x++;
            if(dp[i]==3*dp[y]) y++;
            if(dp[i]==5*dp[z]) z++;
        }
        return dp[n-1];
    }
};

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
