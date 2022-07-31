class Solution {
    vector<vector<long long int>> dp;

    long long int solve(vector<int>&nums, int i,int flag){
        if(i==nums.size())
            return 0;
        
        if(dp[i][flag]!=-1)
            return dp[i][flag];
        
        long long int a = 0, b = 0;
        if(flag==1)
        {
            a = nums[i] + solve(nums, i+1, !flag);
            b = solve(nums, i+1, flag);
        }else{
            a = -nums[i] + solve(nums,i+1, !flag);
            b = solve(nums, i+1, flag);
        }
        
        return dp[i][flag] = max(a, b);
    }
public:    
    long long maxAlternatingSum(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<long long int>(2,-1));
        bool flag = true;
        int i = 0;
        return solve(nums, i, flag);
    }
};


// https://leetcode.com/problems/maximum-alternating-subsequence-sum/discuss/1298878/C%2B%2B-oror-recursion-memoization-explained
