class Solution
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);
        
        // Find a potential celebrity
        while (st.size()>1)
        {
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            if(M[a][b]==1) st.push(b); 
            else st.push(a);
        }
         // Potential candidate?
        int ans = st.top();
        
        int ctr=0;
        for(int i=0;i<n;i++){
            if(i!=ans and (M[i][ans]==0 or M[ans][i]==1)) 
            return -1;
        }
        return ans;
    }
};


class Solution2
{
public:    
    int celebrity(vector<vector<int> >& m, int n) {
        int a=0;
        int b=n-1;
        while(a<=b){  
          if(m[a][b]==1) a++; 
          else b--;
        }
        
      int k=0,l=0;
      for(int j=0;j<n;j++)
      {
          if(m[a][j]==0)
          k++;
      }
      for(int i=0;i<n;i++)
      {
          if(m[i][a]==1)
          l++;
      }
      if(k==n and l==n-1)
      return a;
      else
      return -1;
    }
};



N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 
