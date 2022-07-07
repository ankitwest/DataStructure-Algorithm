class Solution {
public:
    set<vector<int>> res;
    vector<int> temp;
    void solve(int src,vector<int> &nums,int last){
        if(temp.size()>1)
            res.insert(temp);
        
        for(int i=src;i<nums.size();i++){
            if(nums[i] >= last){
                temp.push_back(nums[i]);
                solve(i+1,nums,nums[i]);
                temp.pop_back();
            }else{
                solve(i+1,nums,last);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(0,nums,-101);
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;
    }
};


class Solution2 {
    vector<vector<int>> ans;
    void solve(int src, vector<int>& nums,vector<int>& temp) {
        if(temp.size() > 1) 
            ans.push_back(temp);
        
        unordered_set<int> hash;
        for(int i = src; i < nums.size(); ++i) {
            if((temp.empty() or nums[i] >= temp.back()) and hash.count(nums[i]) == 0) {
                hash.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(i+1, nums, temp);
                temp.pop_back();
               
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(0,nums,temp);
        return ans;
    }
};

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
