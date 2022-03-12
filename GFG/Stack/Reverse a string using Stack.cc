char* reverse(char *s, int len)
{
    stack<char> st; 
    for(int i=0;i<len;i++) 
        st.push(s[i]);
    
    char* str = new char[len];
    // int* arr = new int[len];
    for(int i=0;i<len;i++) {
        s[i] = st.top(); st.pop();
    }
    return s;
}

Input: S="GeeksforGeeks"
Output: skeeGrofskeeG
