class Solution {
    const int mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s(arr.begin(), arr.end());
        unordered_map<int,int> m;
        
        auto solve = [&](const auto& solve,const int &num)->long long{
            long long cnt = 1;
            
            if(m.count(num))
                return m[num];
            
            for(int i=0;i<n;i++){
                if(num % arr[i] == 0 and s.count(num / arr[i])){
                    cnt += solve(solve,arr[i])  *  solve(solve,num / arr[i]);
                    cnt %= mod;
                }
            }
            return m[num] = cnt;
        };
        
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += solve(solve,arr[i]);
            ans %= mod;
        }
        return ans;
    }
};





class Solution{
public:    
    int numFactoredBinaryTrees(vector<int>& arr) {
     int n = arr.size();
        
        // sorting as, we we are doing bottom-up
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> allowed;
        for(int i = 0; i < n; ++i) {
            allowed[arr[i]] = i;
        }
        
        vector<long long> dp(n, 1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(arr[i] % arr[j] == 0) {
                    int rest = arr[i] / arr[j];
                    if(allowed.count(rest)) {
                        dp[i] += dp[j] * dp[allowed[rest]];
                        dp[i] %= MOD;
                    }
                }
            }
        }
        
        long ans = 0;
        for(auto &num : dp) {
            ans += num;
        }
        
        return ans % MOD;
    }
};
