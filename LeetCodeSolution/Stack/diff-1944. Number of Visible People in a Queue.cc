

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
Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
