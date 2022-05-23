

class Solution {
public:// similar to sum of subarrary minimum
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        
        stack<int> st;
        vector<long long> leftMin(n),rightMin(n);
        vector<long long> leftMax(n),rightMax(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) leftMin[i] = -1;
            else leftMin[i] = st.top();
            st.push(i);
        }
         st = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) rightMin[i] = n;
            else rightMin[i] = st.top();
            st.push(i);
        }
        
        st = stack<int>();
        
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]<arr[i]) st.pop();
            if(st.empty()) leftMax[i] = -1;
            else leftMax[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]<=arr[i]) st.pop();
            if(st.empty()) rightMax[i] = n;
            else rightMax[i] = st.top();
            st.push(i);
        }
        
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long leftminSide = i-leftMin[i] , rightminSide = rightMin[i]-i;
            long long leftmaxSide = i-leftMax[i] , rightmaxSide = rightMax[i]-i;
            ans += arr[i]*(leftmaxSide*rightmaxSide-leftminSide*rightminSide);
        }
        return ans;
    }
};
