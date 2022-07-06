class Solution {
public:
    const int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n,0);
        dp[0] = 1;
        
        int tot = 0;
        for(int i = delay;i<n;i++){
            tot = (tot + dp[i-delay])%mod;
            
            if(i-forget>=0)
                tot = (tot - dp[i-forget] + mod)%mod;
            
            dp[i] = tot;
        }
        
        int ans = 0;
        for(int i = n-forget;i<n;i++){
            ans = (ans + dp[i])%mod;
        }
        return ans % mod;
    }
};


/*
4
1
3
*/

Input: n = 6, delay = 2, forget = 4
Output: 5
Explanation:
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
