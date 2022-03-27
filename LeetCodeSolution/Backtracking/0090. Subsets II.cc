

class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx,vector<int>& nums,vector<int>& subset){
        ans.push_back(subset);   // no condition as we have to generate all the subset
        
        for(int i=idx;i<nums.size();i++){
            if(i>idx and nums[i]==nums[i-1]) continue;  //if current one matches with previous one
            subset.push_back(nums[i]);
            helper(i+1,nums,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp;
        helper(0,nums,temp);
        return ans;
    }
};



Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
