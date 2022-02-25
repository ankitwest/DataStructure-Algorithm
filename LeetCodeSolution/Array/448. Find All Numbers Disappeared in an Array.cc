class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>0)  nums[abs(nums[i])-1] *= -1;
        }
         for(int i=0;i<n;i++){
             if(nums[i]>0) v.push_back(i+1);
         }
        return v;
    }
};

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
