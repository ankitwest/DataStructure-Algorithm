class Solution1 {
public:
    const int mod = 1e9+7;
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        long a2 = 0, e2 = 0, i2 = 0, o2 = 0, u2 = 0;
        
        // in which of prev characters, we can place a2 in succession
        for(int k = 2;k <= n; k++){
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = (i) % mod;
            u2 = (i + o) % mod;
            
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        return (a + e + i + o + u) % mod;
    }
};

/*
a -> e
e -> a,i
i -> a,e,o,u
o -> i,u
u -> a
*/

class Solution {
    const int mod = 1e9+7;
    vector<vector<int>> dp;
    int solve(int i,int prev,vector<int> adj[],int n){
        if(i == n)
            return 1;
        
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        
        int ans = 0;
        for(auto& next : adj[prev]){
            ans += solve(i + 1, next, adj, n);
            ans = ans % mod;
        }
        return dp[i][prev] = ans;
    }
public:
    int countVowelPermutation(int n) {
        //making a adj list
        vector<int> adj[5];
        adj[0] = {1};
        adj[1] = {0,2};
        adj[2] = {0,1,3,4};
        adj[3] = {2,4};
        adj[4] = {0};
        
        dp.resize(n, vector<int> (5,-1));
        
        int ans = 0;
        
        ans = (ans + solve(1, 0, adj, n)) % mod;
        ans = (ans + solve(1, 1, adj, n)) % mod;
        ans = (ans + solve(1, 2, adj, n)) % mod;
        ans = (ans + solve(1, 3, adj, n)) % mod;
        ans = (ans + solve(1, 4, adj, n)) % mod;
        
        return ans;
    }
};





