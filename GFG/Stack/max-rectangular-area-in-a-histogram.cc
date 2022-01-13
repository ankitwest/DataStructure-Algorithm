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




class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st; int n = heights.size();
        
        int h,w; int max_area=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n or heights[st.top()]>=heights[i])){
                h = heights[st.top()];
                st.pop();
                if(st.empty()) w=i; else w=i-st.top()-1;
                max_area=max(max_area,h*w);
            }
            st.push(i);
        }
         return max_area;
    }
};







class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> st;
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
