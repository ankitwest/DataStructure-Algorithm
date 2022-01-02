class Solution{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> st;
        vector<int> left(n),right(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]>=arr[i]){     // we are looking for such index which could yield me a height less than the current one 
                st.pop();
            }
            if(st.empty()) left[i]=0;
            else left[i]=st.top()+1;   // stopping one element to the right
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) right[i]=n-1;
            else right[i]=st.top()-1;   // stopping one element to the left 
            st.push(i);
        }
        
         long long max_area=0;
       for(int i=0;i<n;i++){
           max_area=max(max_area,arr[i]*(right[i]-left[i]+1));   // as we calculate the width
       }         
       return max_area; 
    }
};
