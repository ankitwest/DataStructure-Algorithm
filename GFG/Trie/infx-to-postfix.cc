// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c){
        if(c=='^') return 3;
        else if(c=='/' or c=='*') return 2;
        else if(c=='+' or c=='-') return 1;
        else return -1;
    }
    string infixToPostfix(string s) {
        stack<char> st;
        string ans; int n = s.size();
        
        for(int i=0;i<n;i++){
            char c = s[i];
            if ((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z') or (s[i]>='0' and s[i]<='9'))
                ans += s[i];
            else if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')'){
                while(st.top()!='('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() and prec(s[i]) <= prec(st.top())){
                    if (c == '^' && st.top() == '^')
                        break;
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends
