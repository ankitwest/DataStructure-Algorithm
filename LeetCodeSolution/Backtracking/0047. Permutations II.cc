
// Pass by value only possible

class Solution {
public:
    // in this pass by refernce gives wrong answer
    vector<vector<int>> ans;
    void helper(int idx,vector<int> nums,int n){
        if(idx==n)
            ans.push_back(nums);
        
        for(int i=idx;i<n;i++){
            if(i!=idx and nums[i]==nums[idx]) continue;
            swap(nums[i],nums[idx]);
            helper(idx+1,nums,n);
            // swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        helper(0,nums,n);
        return ans;
    }
};

// TC - n*n!
// we can also use set , but TC will be (log n) extra



//latest
class Solution {
public:
    //*** in this pass by refernce gives wrong answer   and also swap
    vector<vector<int>> ans;
    void helper(int idx,vector<int> nums,int n){
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<n;i++){
            // if(i>idx and nums[i]==nums[idx]) continue;
            if(i==idx || nums[i]!=nums[idx]){ 
                swap(nums[i],nums[idx]);
                helper(idx+1,nums,n);
                // swap(nums[i],nums[idx]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        helper(0,nums,n);
        return ans;
    }
};

