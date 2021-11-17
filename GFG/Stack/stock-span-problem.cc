class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n){
        vector<int> span(n);
      stack<int>st;
      st.push(0);
      span[0]=1;
      
      for(int i=1;i<n;i++){
          while(!st.empty() and price[st.top()]<=price[i])
            st.pop();
          if(st.empty()) span[i]=i+1; 
          else span[i]=i-st.top();
          st.push(i);
      }
      return span;
    }
};
