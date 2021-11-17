class Solution{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> st;
        stack<int> stLeft,stRight;
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) left[i]=i+1;
            else left[i]=i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) right[i]=n-i;
            else right[i]=st.top()-i;
            st.push(i);
        }
         long long max_area=0;
       for(int i=0;i<n;i++){
           max_area=max(max_area,arr[i]*(right[i]+left[i]-1));
       }
       return max_area; 
    }
};
