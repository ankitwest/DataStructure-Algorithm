class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        
        stack<int> st;
        vector<long long> leftMin(n,-1),rightMin(n,n);
        vector<long long> leftMax(n,-1),rightMax(n,n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]>arr[i]) st.pop();
            if(!st.empty()) leftMin[i] = st.top();
            st.push(i);
        }
         while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) rightMin[i] = st.top();
            st.push(i);
        }
        
        st = stack<int>();
        
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]<arr[i]) st.pop();
            if(!st.empty()) leftMax[i] = st.top();
            st.push(i);
        }
         while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]<=arr[i]) st.pop();
            if(!st.empty()) rightMax[i] = st.top();
            st.push(i);
        }
        
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long leftmin = i-leftMin[i] , rightmin = rightMin[i]-i;
            long long leftmax = i-leftMax[i] , rightmax = rightMax[i]-i;
            ans += arr[i]*(leftmax*rightmax-leftmin*rightmin);
        }
        return ans;
    }
};
