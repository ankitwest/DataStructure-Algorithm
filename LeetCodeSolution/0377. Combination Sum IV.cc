class Solution {

public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int n : nums) {
                if (i >= n) {
                    dp[i] += dp[i - n];
                }
            }
        }
        return dp[target];
    }
};


Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
