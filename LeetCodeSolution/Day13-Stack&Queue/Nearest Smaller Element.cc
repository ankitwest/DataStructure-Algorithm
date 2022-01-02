vector<int> Solution::prevSmaller(vector<int> &nums) {
     stack<int> st;        int n = nums.size();
        reverse(nums.begin(),nums.end());
        vector<int> ans(n,0);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top()>=nums[i])
                st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
