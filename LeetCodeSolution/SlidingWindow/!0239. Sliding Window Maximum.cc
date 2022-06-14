// M-1 O(NlogN)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
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




// O(N)
class Solution {
public:  
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(!dq.empty() and dq.front()==i-k) dq.pop_front(); //only window size of k is allowed
            
            while(!dq.empty() and nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
            
            if(i+1>=k) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

