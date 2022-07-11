class Solution {
public:   //lis
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;
        
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1); 
        vector<int> hash(n,-1);
        
        int maxi = 1;  int last_idx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i] % nums[j]==0) and 1 + dp[j] > dp[i] ){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                last_idx = i;
            }
        }
        
        vector<int> ans;
        while(last_idx != -1){
            ans.push_back(nums[last_idx]);
            last_idx = hash[last_idx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
