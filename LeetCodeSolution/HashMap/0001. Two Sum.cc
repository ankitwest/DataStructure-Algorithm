    
//Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int req = target - nums[i];
            if(m.find(req)!=m.end()){
                v.push_back(m[req]);
                v.push_back(i);
                return v;
            }
            m[nums[i]] = i;
        }
        return v;
    }
};
