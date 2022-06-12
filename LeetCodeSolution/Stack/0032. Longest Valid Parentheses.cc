class Solution1 {
public:  // TC - O(N) SC - O(N)
    int longestValidParentheses(string s) {
        stack<int> st; int maxi = 0;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else maxi = max(maxi, i - st.top());
            }
        }
        return maxi;
    }
};

// M-2
class Solution {
public:    // TC - O(N) SC - O(1)
    int longestValidParentheses(string s) {
        int ans = 0;  int open = 0;int close = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')  open++;
            else close++;
            if(open == close) ans = max(ans, open + close);
            else if(close > open) open = close = 0;
        }
        
         open = 0;close = 0;
         for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')  open++;
            else close++;
            if(open == close) ans = max(ans, open + close);
            else if(close > open) open = close = 0;
        }
        
        return ans;
    }
};

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
