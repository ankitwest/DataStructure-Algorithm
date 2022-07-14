class Solution{
  public:
    int fun(string &s) {
        const long long int mod = 1e9 + 7;
        long long int a = 0, ab = 0, abc = 0;
        
        for(char ch: s) {
            // 1. Append a to a's
            // 2. Start new string with a.
            if(ch == 'a') a = ((2*a)%mod + 1) % mod;
            
            // 1. Append b to ab's
            // 2. Append b directly to a's
            if(ch == 'b') ab = ((2*ab)%mod + a) % mod;
            
            // 1. Append c to abc's
            // 2. Append c directly to ab's
            if(ch == 'c') abc = ((2*abc)%mod + ab) % mod;
        }
        
        return abc;
    }
};

Input:
S = "abbc"
Output: 3
Explanation: Subsequences are abc, abc and abbc.

Example 2:

Input:
S = "abcabc"
Output: 7
Explanation: Subsequences are abc, abc,
abbc, aabc abcc, abc and abc.
