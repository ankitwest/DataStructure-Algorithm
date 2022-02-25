class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0) v.push_back(abs(nums[i]));
            else nums[abs(nums[i])-1] *= -1;
        }
        return v;
    }
};


Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
