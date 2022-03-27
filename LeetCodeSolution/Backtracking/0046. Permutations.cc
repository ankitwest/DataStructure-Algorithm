
// Passing the array by reference

class Solution {
public:
    // here back swap because we are making changes in the given array everytime we are calling helper function ;and we need to come back to zero;
    vector<vector<int>> ans;
    void helper(int idx,vector<int> &nums,int n){
        if(idx==n)
            ans.push_back(nums);
        
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            helper(idx+1,nums,n);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        helper(0,nums,n);
        return ans;
    }
};

// TC - n*n!
// No extra space is used  here

// In approach 1 , we use a vector where we push and pop ; and vis array to keep track of element;





// Passing the array by value

class Solution {
public:
    // here no back swap because we are creating new array everytime we are calling helper function
    vector<vector<int>> ans;
    void helper(int idx,vector<int> nums,int n){
        if(idx==n)
            ans.push_back(nums);
        
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            helper(idx+1,nums,n);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        helper(0,nums,n);
        return ans;
    }
};

// TC - n*n!
// No extra space is used  here

// In approach 1 , we use a vector where we push and pop ; and vis array to keep track of element;









// M-2

class Solution {
public:
    // here back swap because we are making changes in the given array everytime we are calling helper function ;and we need to come back to zero;
    vector<vector<int>> ans;
    void helper(int idx,vector<int> &nums,int n){
        if(idx==n)
            ans.push_back(nums);
        
        for(int i=idx;i<n;i++){
            temp.push_back(nums[i]);
            helper(idx+1,nums,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        helper(0,nums,n);
        return ans;
    }
};
