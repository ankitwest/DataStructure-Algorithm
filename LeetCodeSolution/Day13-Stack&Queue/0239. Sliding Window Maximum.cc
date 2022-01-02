class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d; int n = nums.size();
        vector<int> ans;
        multiset<int,greater<int>>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            if(s.size()>k) s.erase(s.find(nums[i-k]));
            if(s.size()==k) ans.push_back(*s.begin());
        }
        return ans;
    }
};
