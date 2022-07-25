class Solution {
public:
    long long mod = 1e9 + 7;
    int maxSumMinProduct(vector<int>& nums) {
        vector<int> heights = nums;
        
        stack<int> st; int n = heights.size();
        vector<int>left(n,-1),right(n,n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()] >= heights[i])  // we are looking for such index which could yield me a height less than the current one 
                st.pop();
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty()) right[i] = n;
            else right[i] = st.top(); 
            st.push(i);
        }
        
        
        vector<long long> pre_sum(n+1,0);
        for(int i=0;i<n;i++){
            pre_sum[i+1] = pre_sum[i] + nums[i];
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        
        long long ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            long long t = (pre_sum[right[i]] - pre_sum[left[i] + 1]) * nums[i];
            ans = max(ans, t);
        }
        return ans % mod;
    }
};

