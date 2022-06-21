class Solution1 {
public: 
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int max_sub_sum = 0; int sum = 0;  
        for(int i=0;i<n;i++){
            sum += nums[i];
            max_sub_sum = max(max_sub_sum,sum);
            if(sum < 0) sum = 0; 
        }
        int min_sub_sum = 0;  sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            min_sub_sum = min(min_sub_sum,sum);
            if(sum > 0) sum = 0; 
        }
        return max(max_sub_sum, -min_sub_sum);
    }
};

// max of these two : max_subarray_sum , -min_subarray_sum


class Solution {
public:   // TC - O(N)
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int max_sub_sum = 0;int min_sub_sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            max_sub_sum = max(0, max_sub_sum + nums[i]);
            min_sub_sum = min(0, min_sub_sum + nums[i]);
            ans = max(ans, max(max_sub_sum , -min_sub_sum));
        }
        return ans;
    }
};



Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
