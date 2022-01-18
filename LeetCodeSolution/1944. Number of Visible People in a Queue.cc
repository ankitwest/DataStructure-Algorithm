class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st; int n = heights.size();
        vector<int> see(n);
        for(int i=n-1;i>=0;i--){
            int cnt = 0;
            while(!st.empty() and st.top()<heights[i]){
                cnt++;
                st.pop();
            }
            see[i] = cnt+!st.empty();
            st.push(heights[i]);
        }
        return see;
    }
};
