class Solution {
public:
    int dp[505][2005];
    int solve(int i,int rem,vector<int>& arr,int k){
        if(i == arr.size())
            return 0;
            
        if(dp[i][rem]!=-1)
            return dp[i][rem];
            
        int ans = 0;
        if(arr[i] > rem){
            ans = (rem + 1)*(rem + 1) + solve(i+1, k-arr[i]-1, arr, k);
        }else{
            int choice1 =  (rem + 1)*(rem + 1) + solve(i+1, k-arr[i]-1, arr, k);
            int choice2 = solve(i+1, rem-arr[i]-1, arr, k);
            ans = min(choice1, choice2);
        }
        return dp[i][rem] = ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,k,nums,k);
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
