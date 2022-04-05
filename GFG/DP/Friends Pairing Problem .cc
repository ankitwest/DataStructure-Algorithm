


class Solution
{
public:
const int mod = 1e9+7;
    vector<long long int> dp;
    long long int solve(int n){
        if(n<=2)
            return n;
        
        if(dp[n]!=-1)
            return dp[n];
            
        long long int ans = (solve(n-1) + ((n-1)*solve(n-2))%mod)%mod;
        return dp[n] = ans%mod;
    }
    int countFriendsPairings(int n) 
    { 
        // if he is single recur for f(n-1)
        // else to pair up (n-1)*f(n-2)
        dp.resize(n+1,-1);
       return solve(n)%mod;
    }
    };


n = 3

{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.
