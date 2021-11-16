class Solution{
  public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int no=n;
        stack<int> st;
        while(n--) st.push(n);
        
        int i=1;n=no;
        while(i<n){
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            if(M[a][b]==1) st.push(b); 
            else st.push(a);
            i++;
        }
        int ans = st.top();
        
        int ctr=0;
        for(int i=0;i<n;i++){
            if(i==ans) continue;
            if(M[i][ans]==1 and M[ans][i]==0) ctr++;
            else return -1;
        }
        if(ctr==n-1) ; else return -1; 
        return ans;
    }
};
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 
