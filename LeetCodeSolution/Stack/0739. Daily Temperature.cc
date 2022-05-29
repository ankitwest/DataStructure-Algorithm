// next greater element

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;  int n = temp.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and temp[st.top()]<=temp[i]) 
                st.pop();
            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
