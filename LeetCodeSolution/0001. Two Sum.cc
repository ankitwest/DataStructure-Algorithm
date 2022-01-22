class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int no1= nums[i];
            int no2= target- no1;
            if(m.find(no2)!=m.end()){
                int j =  m[no2];
                ans.push_back(i),ans.push_back(j);
            }
            m[no1]=i;
        }
        return ans;
    }
    
};
