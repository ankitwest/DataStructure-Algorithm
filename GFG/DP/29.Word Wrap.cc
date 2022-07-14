class Solution{
  public:
  vector<int> dp;
    // no idea what's going on
    int solve(int ind,int n,vector<int>& nums,int k){
        if(ind>=n) 
            return 0;
        if(dp[ind]!=-1) 
            return dp[ind];
        
        int ans = INT_MAX;
        int sum = 0;
        
        for(int i=ind;i<n;i++){
            sum += nums[i];
            if(sum + (i-ind)<=k){
                int cost = 0;
                if(i!=n-1)
                    cost = pow(k-sum-i+ind,2);
                
                ans = min(ans,cost+solve(i+1,n,nums,k));
            }
        }
        return dp[ind] = ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        dp.resize(n,-1);
        return solve(0,n,nums,k);
    } 
};



Input: nums = {3,2,2,5}, k = 6
Output: 10
Explanation: Given a line can have 6
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4
So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10.
As in the first line word length = 3 thus
extra spaces = 6 - 3 = 3 and in the second line
there are two word of length 2 and there already
1 space between two word thus extra spaces
= 6 - 2 -2 -1 = 1. As mentioned in the problem
description there will be no extra spaces in
the last line. Placing first and second word
in first line and third word on second line
would take a cost of 02 + 42 = 16 (zero spaces
on first line and 6-2 = 4 spaces on second),
which isn't the minimum possible cost.
