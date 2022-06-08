class Solution {
public:
    int robber(vector<int> &nums){
        int n = nums.size();
        int dp[n];
        fill(dp,dp+n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1] , nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        vector<int> v(nums.begin(),nums.end());
        
        return robber(v);
    }
};



class Solution {
public:
    int robber(vector<int> &nums){
        int n = nums.size();
        int dp[n]; fill(dp,dp+n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1] , nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max({nums[0],nums[1],nums[2]});
        
        vector<int> v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin()+1,nums.end());
        
        return max(robber(v1),robber(v2));
    }
};
