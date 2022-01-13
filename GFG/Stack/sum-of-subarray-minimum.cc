class Solution {
public:
    const int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();

    stack<int> st;
    vector<int> left(n),right(n);

    for(int i=0;i<n;i++){
        while(!st.empty() and arr[st.top()] > arr[i])
            st.pop();
        if(st.empty()) left[i] = i+1;   //0
        else left[i] = i-st.top();      //st.top()+1

        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--){
        while(!st.empty() and arr[st.top()] >= arr[i])
            st.pop();
        if(st.empty()) right[i] = n-i;  //n-1
        else right[i] = st.top()-i;    //st.top()-1

        st.push(i);
    }
         for(int i=0; i<n; i++) cout << left[i] << " : " << right[i] << endl;
        cout<<endl;
    long long sum = 0 , noOfSubarray = 1 , contri = 1;
    for(int i=0;i<n;i++){
        noOfSubarray = (left[i]*right[i])%MOD;
        contri = (noOfSubarray*arr[i])%MOD;
        sum = (sum+contri)%MOD;
    }

    return sum%MOD;
    }
};
