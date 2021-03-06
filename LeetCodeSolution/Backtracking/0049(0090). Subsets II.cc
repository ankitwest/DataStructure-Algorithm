class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx,vector<int>& nums,vector<int>& subset){
        ans.push_back(subset);   // no condition as we have to generate all the subset
        //try generating of every size = 0,1,2,3...
        
        for(int i=idx;i<nums.size();i++){
            // if(i>idx and nums[i]==nums[i-1]) continue;  //if current one matches with previous one
            if(i==idx || nums[i]!=nums[i-1]){   //first element h to daal do uske baad don't add duplicates
                subset.push_back(nums[i]);
                helper(i+1,nums,subset);   // size + 1
                subset.pop_back();
            }
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


// if(i!=ind && arr[i]==arr[i-1]) continue;








Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]




class Solution2 {
public:
    set<vector<int>> s;
    void helper(int idx,vector<int>& nums,vector<int>& subset){
        if(idx==nums.size()){
            s.insert(subset);
            return;
        }
        // not taking
        helper(idx+1,nums,subset);
        
        //taking
        subset.push_back(nums[idx]);
        helper(idx+1,nums,subset);
        subset.pop_back();
    }
     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp;
        helper(0,nums,temp);
         
         vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};

