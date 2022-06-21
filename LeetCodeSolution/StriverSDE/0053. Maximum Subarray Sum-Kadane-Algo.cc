class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0; int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxi = max(sum,maxi);
            if(sum<0) sum = 0;
        }
        return maxi;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub_sum = 0; int ans = 0;
        for(int i=0;i<nums.size();i++){
            max_sub_sum = max(0, max_sub_sum + nums[i]);
            ans = max(ans,max_sub_sum);
        }
        return ans;
    }
};




Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
