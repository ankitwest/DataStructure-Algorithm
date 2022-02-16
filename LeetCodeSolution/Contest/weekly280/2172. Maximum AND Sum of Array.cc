class Solution {
public:
    
    int f(int ind,vector<int> &slotWt,vector<int> &nums,int numSlots,map<pair<int,vector<int>>,int> &dp){
        if(ind>=nums.size())
            return 0;
        
        int maxi= INT_MIN;
        
        if(dp.find({ind,slotWt}) != dp.end())
            return dp[{ind,slotWt}];
        
        for(int k=1;k<=numSlots;k++){
            if(slotWt[k]<2){
                slotWt[k]++;
                int ans = (nums[ind]&k) + f(ind+1,slotWt,nums,numSlots,dp);
                slotWt[k]--;
                maxi = max(maxi,ans);
            }
        }
        return dp[{ind,slotWt}] = maxi;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> slotWt(numSlots+1,0);
        map<pair<int,vector<int>>,int> dp;
        return f(0,slotWt,nums,numSlots,dp);
    }
};


Input: nums = [1,3,10,4,7,1], numSlots = 9
Output: 24
Explanation: One possible placement is [1, 1] into slot 1, [3] into slot 3, [4] into slot 4, [7] into slot 7, and [10] into slot 9.
This gives the maximum AND sum of (1 AND 1) + (1 AND 1) + (3 AND 3) + (4 AND 4) + (7 AND 7) + (10 AND 9) = 1 + 1 + 3 + 4 + 7 + 8 = 24.
Note that slots 2, 5, 6, and 8 are empty which is permitted.
