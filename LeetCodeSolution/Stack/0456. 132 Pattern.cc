


class Solution2 {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int minVal[n]; minVal[0] = nums[0];
        for(int i=1;i<n;i++){
            minVal[i] = min(minVal[i-1],nums[i]);
        }
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top()<=minVal[i])
                st.pop();
            
            if(!st.empty() and st.top()<nums[i]) return true;
            
            st.push(nums[i]);
        }
        return false;
    }
};


// better relatable

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int minVal[n]; minVal[0] = nums[0];
        for(int i=1;i<n;i++){
            minVal[i] = min(minVal[i-1],nums[i]);
        }
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top()>=nums[i])
                st.pop();
            
            if(!st.empty() and st.top()>minVal[i]) return true;
            
            st.push(nums[i]);
        }
        return false;
    }
};


Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
