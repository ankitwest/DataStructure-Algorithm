
// 1047. Remove All Adjacent Duplicates In String

class Solution2 {
public:   // TLE
    string ans = "";
    void solve(string str,int i){
        if(i>=str.size()){
            ans = str;
            return;
        }
        
        if(i+1<str.size() and str[i]==str[i+1])
            solve(str.substr(0,i)+str.substr(i+2),0);
        else
            solve(str,i+1);
    }    
    string removeDuplicates(string s) {
        solve(s,0);
        return ans;
    }
};
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size(); stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() and st.top()==s[i]) st.pop();
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};    




// 1209. Remove All Adjacent Duplicates in String II


class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st; int n = s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() and st.top().first==s[i]){
                auto [ch,cnt] = st.top(); st.pop();
                st.push({s[i],cnt+1});
            }else{
                st.push({s[i],1});
            }
            if(st.top().second==k) st.pop();
        }
        
        string ans="";
        while(!st.empty()){
             auto [ch,cnt] = st.top(); st.pop();
            while(cnt--) ans += ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
