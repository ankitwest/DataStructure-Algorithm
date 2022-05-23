

class Solution {
public:
    const long long mod = 1e9+7;
    int totalStrength(vector<int>& arr) {
        int n = arr.size(); 
        vector<long long> preSum(n+1,0LL);
        vector<long long> prePrefix(n+2,0LL);
        
        for(int i=0;i<n;i++){    // sum of first k elements
            preSum[i+1] = (preSum[i] + arr[i])%mod;
        }
        for(int i=0;i<=n;i++){   // sum of first k prefix
            prePrefix[i+1] = (prePrefix[i] + preSum[i])%mod;
        }
        
        vector<long long> left(n,0),right(n,0);
        stack<long long> st;
        
        // first index on left < current value
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        // first index on right <= current value
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()] > arr[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        // positive parts:
        // (prefix[i + 1] + prefix[i + 2] + ... + prefix[right]) * (i - left) = (prePrefix[right[i] + 1] - prePrefix[i + 1]) * (i - left[i])
        // negative parts:
        // (prefix[left + 1] + prefix[left + 2] + ... + prefix[i]) * (right - i) = (prePrefix[i + 1] - prePrefix[left[i] + 1]) * (right[i] - i)
    
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long L = left[i]; long long R = right[i];
            long long pos = ((prePrefix[R + 1] - prePrefix[i + 1]) * (i - L)) % mod;
            long long neg = ((prePrefix[i + 1] - prePrefix[L + 1]) * (R - i)) % mod;
            ans += ((pos - neg) % mod + mod) * arr[i] % mod;
            ans %= mod;
        }
        return ans;
    }
};


