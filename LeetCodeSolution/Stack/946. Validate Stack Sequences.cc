class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(); int i=0; int j=0;
        stack<int> st;
        while(i<n or j<n){
            if(st.empty())
                st.push(pushed[i]),i++;
            else if(st.top()==popped[j])
                st.pop(),j++;
            else if(i==n)
                return false;
            else
                st.push(pushed[i]),i++;
            }
        return true;
    }
};


Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
