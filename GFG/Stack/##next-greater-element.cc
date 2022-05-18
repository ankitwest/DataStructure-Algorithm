class Solution{
  public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> v(n);
      stack<long long>st;
      
      // immediate
        // next greater <     next smaller >
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
Input: 
N = 5, arr[] [6 8 0 1 3]
Output:
8 -1 1 3 -1

  
  
  vector<long long> all4kind(vector<long long> arr, int n){
        vector<long long> next(n);
      stack<long long>st;
      
   // immediate
      // next greater <     next smaller >
      for(int i=n-1;i>=0;i--){
          while(!st.empty() and st.top()<arr[i])
            st.pop();
          if(!st.empty()) next[i]=st.top();
          else next[i]=-1;
          st.push(arr[i]);
      }
      return next;
      
      
      vector<long long> prev(n);
   // immediate
      // previous greater <     previous smaller >
      for(int i=0;i<n;i++){
          while(!st.empty() and st.top()>arr[i])
            st.pop();
          if(!st.empty()) prev[i]=st.top();
          else prev[i]=-1;
          st.push(arr[i]);
      }
      return prev;
    }
