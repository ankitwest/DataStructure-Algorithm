
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       int n = nums.size();
        if(n<=2) return 0;
        vector<unordered_map<long,int>> dp(n);
        
        long ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((long)nums[i] - (long)nums[j] > INT_MAX) continue;
                if((long)nums[i] - (long)nums[j] < INT_MIN) continue;
                
                long diff = (long)nums[i] - (long)nums[j];
                dp[i][diff] += 1;
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                }
            }
        }
        return ans;
    }
};
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
  
  
Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
