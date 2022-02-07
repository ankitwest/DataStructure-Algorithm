

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        
        for(int window=1;window<=n;window++){
            for(int left=1;left<=n-window+1;left++){
                int right = left+window-1;
                int maxi = INT_MIN;
                for(int k=left;k<=right;k++){
                    int tot = dp[left][k-1]+dp[k+1][right]+nums[left-1]*nums[k]*nums[right+1];
                    maxi = max(maxi,tot);
                }
                dp[left][right] = maxi;
            }
        }
        return dp[1][n];
    }
};

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
