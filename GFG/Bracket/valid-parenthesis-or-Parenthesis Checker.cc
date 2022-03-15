class Solution{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
    map<char,char> m;
        stack<char> st;
        m[')']='(';
        m['}']='{';
        m[']']='[';
        st.push(x[0]);
        
        for(int i=1;i<x.size();i++){
            char ch = x[i];
            if(!st.empty() and st.top()==m[ch]) 
                st.pop();
            else  
                st.push(ch);
        }
        if(st.empty()) return true;
        else return false;
    }
};
Expected Time Complexity: O(|x|)
    
    
    
Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.
