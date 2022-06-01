


class Solution {
public:
    vector<vector<int>> dp; 
    bool solve(int ind,int sum,vector<int>& nums){
        if(sum==0)
            return true;
        if(sum<0)
            return false;
        if(sum>0 and ind>=nums.size())
            return false;
       
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        bool a = solve(ind+1,sum-nums[ind],nums);
        bool b = solve(ind+1,sum,nums);
        
        return dp[ind][sum] = (a or b);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false; 
        int n = nums.size();
        dp.resize(n+1,vector<int>(sum+1,-1));
        
        return solve(0,sum/2,nums);
    }
};



// dp.resize(-1)  will only give right answer dp.resize(0) wwn't







// Tabulation
class Solution{
public:
     bool canPartition(vector<int>& arr){
         
         int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum&1) return false;
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum/2+1));
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
         for(int j=0;j<=sum/2;j++){
             dp[0][j] = 0;
         }
         dp[0][0] = 1;
        
       bool take = false;
	   bool notTake = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                 if(j>=arr[i-1]) {
	                take = dp[i-1][j-arr[i-1]];
	            }
	                
	           notTake = dp[i-1][j];
	           dp[i][j] = take or notTake;
            }
        }
        return dp[n][sum/2];
     }
};
