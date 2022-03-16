


int countRev (string s)
{
    stack<char> st;
    int ans=0;
    if(s.size()&1) return -1;
    for(int i=0;i<s.size();i++)
    {
        if(st.empty())
            st.push(s[i]);
        else if(st.top()=='{' and s[i]=='}')
            st.pop();
        else 
            st.push(s[i]);
    }
    
    while(!st.empty()){
        char t1 = st.top(); st.pop();
        char t2 = st.top(); st.pop();
        
        if(t1==t2)
            ans++;
        else
            ans+=2;
    }
    return ans;
}



// M-2

int countRev (string s)
{
    if(s.size()&1) return -1;
    
    int left=0; int right=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{') left++;
        else if(s[i]=='}'){
            if(left>0) left--;
            else right++;
        }
    }

    int ans = left/2 + right/2 + left%2 + right%2;
    return ans;
}


Input:
S = "}{{}}{{{"
Output: 3

