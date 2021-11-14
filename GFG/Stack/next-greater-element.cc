class Solution{
  public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> v(n);
      stack<long long>st;
      for(int i=n-1;i>=0;i--){
          while(!st.empty() and st.top()<arr[i])
            st.pop();
          if(st.empty()) v[i]=-1; 
          else v[i]=st.top();
          st.push(arr[i]);
      }
      return v;
    }
};
Expected Time Complexity : O(N)
