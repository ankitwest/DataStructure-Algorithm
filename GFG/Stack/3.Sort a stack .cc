
void SortedStack :: sort()
{
    if(s.size() <= 1) return;
    int elem = s.top();
    s.pop();
    sort();
    
    stack<int> st;
    while(!s.empty() && s.top() > elem) {
        st.push(s.top());
        s.pop();
    }
    
    s.push(elem);
    
    while(!st.empty()) {
        s.push(st.top());
        st.pop();
    }
}

Stack: 11 2 32 3 41
Output: 41 32 11 3 2
