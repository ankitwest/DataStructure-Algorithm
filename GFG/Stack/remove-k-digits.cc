class Solution{
  public:
    string removeKdigits(string S, int K) {
        stack<char> st;
        for(int i=0;i<S.size();i++){
            while(!st.empty() and st.top()>S[i] and K>0){
                st.pop(); K--;
            }
            // if(!st.empty() or S[i]!='0') st.push(S[i]);
            if(st.empty() and S[i]=='0') continue; else st.push(S[i]);
        }
        
        while(!st.empty() and K>0){
            st.pop(); K--;
        }
        if(st.empty()) return "0";
        
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;st.pop();
        }
        return ans;
    }
};

Expected Time Complexity: O(|S|).
