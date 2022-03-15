class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                if(st.empty())
                    s[i]='#';
                else st.pop();
            }
        }
        
        while(!st.empty()){
            s[st.top()] = '#'; st.pop();
        }
        
        string ans;
        for(auto c:s){
            if(c!='#') ans+=c;
        }
        return ans;
    }
};

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
  
  
//   without stack

M -2
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int ctr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                ctr++;
            else if(s[i]==')'){
                if(ctr==0)
                    s[i]='#';
                else ctr--;
            }
        }
        ctr=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')
                ctr++;
            else if(s[i]=='('){
                if(ctr==0)
                    s[i]='#';
                else ctr--;
            }
        }
        
        string ans;
        for(auto c:s){
            if(c!='#') ans+=c;
        }
        return ans;
    }
    
};
