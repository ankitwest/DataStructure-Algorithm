class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx,vector<int>& nums,vector<int>& subset){
        ans.push_back(subset); // try generating of every size = 0,1,2,3...
           
        for(int i=idx;i<nums.size();i++){
            subset.push_back(nums[i]);
            helper(i+1,nums,subset);  // size+1
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        helper(0,nums,subset);
        return ans;
    }
};
// try this one
//similar to subsets 2
class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx,vector<int>& nums,vector<int>& subset){
        ans.push_back(subset); // try generating of every size = 0,1,2,3...
           
        for(int i=idx;i<nums.size();i++){
            if(i==idx || nums[i]!=nums[i-1]){ //first element h to daal do uske baad don't add duplicates
                subset.push_back(nums[i]);
                helper(i+1,nums,subset);  // size+1
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        helper(0,nums,subset);
        return ans;
    }
};








class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx,vector<int>& nums,vector<int>& subset){
        if(idx==nums.size()){
            ans.push_back(subset);
            return ;
        }
            
        helper(idx+1,nums,subset); 
        
        subset.push_back(nums[idx]);
        helper(idx+1,nums,subset); 
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        helper(0,nums,subset);
        return ans;
    }
};

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
