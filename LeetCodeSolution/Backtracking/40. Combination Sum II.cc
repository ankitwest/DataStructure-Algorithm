

class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, int target, vector<int>&nums,vector<int>&ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(target<0)
            return ;
        
        for(int i = index; i< nums.size(); i++){
            // if(nums[i] > target) break; // no point of it to add it to the ans 
            if(i > index && nums[i] == nums[i-1])  //to avoid picking up the same elements and thus avoiding duplicates 
                continue;
            ds.push_back(nums[i]);
            helper(i+1,target-nums[i],nums,ds); //call for next index element
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums,int target) {
        sort(nums.begin(), nums.end()); 
        vector<int>ds;
        helper(0,target,nums,ds);
        return ans;
    }
};

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
