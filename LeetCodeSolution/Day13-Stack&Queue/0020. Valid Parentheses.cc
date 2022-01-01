class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto c:s){
            if(c=='(' or c=='{' or c=='[')  st.push(c);
            else{
                if(st.empty()) return false;
                else if((st.top()=='(' and c!=')') or (st.top()=='{' and c!='}') or (st.top()=='[' and c!=']') ) return false;
                else st.pop();
            }
                
        }
        return st.empty();
    }
};
