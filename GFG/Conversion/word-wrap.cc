
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

