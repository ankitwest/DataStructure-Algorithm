class Solution1
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
            if(i!=ans){
                if(M[i][ans]==0 or M[ans][i]==1)
                    return -1;
            }
        }
        return ans;
    }
};

// two pointer technique
class Solution
{
public: 
    int celebrity(vector<vector<int> >& M, int n) {
        int i=0;
        int j=n-1;
        while(i<j){  
           if(M[i][j]==1) i++; //i can't be celebrity
           else j--;
        }
        // j points to our celebrity candidate
        int candidate = j;

        for(int i=0;i<n;i++)
        {
            if(i!=candidate){
                if(M[i][candidate]==0 or M[candidate][i]==1)
                    return -1;
            }
             
        }
        return candidate;
    }
};



N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 
