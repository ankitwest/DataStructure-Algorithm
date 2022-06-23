class Solution1 {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                if(st.empty()) s[i]='#';
                else st.pop();
            }
        }
        
        while(!st.empty()){
            int top = st.top(); st.pop();
            s[top] = '#'; 
        }
        
        string ans;
        for(auto c:s){
            if(c!='#') ans+=c;
        }
        return ans;
    }
};


// M -2
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int ctr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ctr++;
            }else if(s[i]==')'){
                if(ctr==0) s[i]='#';
                else ctr--;
            }
        }
        ctr=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){
                ctr++;
            }else if(s[i]=='('){
                if(ctr==0) s[i]='#';
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
