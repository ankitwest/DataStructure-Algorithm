class Solution1 {
public:   // TC - O(KlogN)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        vector<int> v;
        for(int i=0;i<k;i++){
            auto a = pq.top();pq.pop();
            int b = a.second;
            v.push_back(b);
        }
        return v;
    }
};


// M-2  using bucket sort
class Solution {
public:  //  TC - O(N+K)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return {};
        
        vector<vector<int>> bucket(n+1);
        unordered_map<int,int>m;
        for(auto i:nums) m[i]++;
        
        for(auto [x,y]:m){
            bucket[y].push_back(x);
        }
        
        vector<int> ans;
        for(int i=bucket.size()-1;i>=0;i--){
            for(int j=0;j<bucket[i].size();j++){
                ans.push_back(bucket[i][j]);
                if(ans.size()==k) return ans;
            }
        }
        return {};
    }
};

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
