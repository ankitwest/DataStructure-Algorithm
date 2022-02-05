

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        
        int mid = INT_MAX;
        int low = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<low) low = nums[i];
            else if(nums[i]>low and nums[i]<mid) mid = nums[i];
            else if(nums[i]>mid) return true;
        }
        return false;
    }
};


Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
