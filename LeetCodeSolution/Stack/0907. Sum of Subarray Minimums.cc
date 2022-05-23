

class Solution {
public:  //better approach // first smaller element ; then size of subarray ; then noOfSubarray
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;
        vector<int> left(n),right(n);

        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty()) left[i] = -1;        
            else left[i] = st.top();            
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()] > arr[i])
                st.pop();
            if(st.empty()) right[i] = n;      
            else right[i] = st.top();           
            st.push(i);
        }

        vector<int> leftSide(n),rightSide(n);
        for(int i=0; i<n; i++) leftSide[i] = i - left[i];
        for(int i=0; i<n; i++) rightSide[i] = right[i] - i;
        for(int i=0; i<n; i++) cout << leftSide[i] << " : " << rightSide[i] << endl;  cout<<endl;

        long long sum = 0 , noOfSubarray = 1 , contri = 1;
        for(int i=0;i<n;i++){
            noOfSubarray = (leftSide[i] * rightSide[i]) % mod;  // calculate size of left and right beforehand
            contri = (noOfSubarray * arr[i]) % mod;
            sum = (sum + contri) % mod;
        }
        return sum%mod;
    }
};
