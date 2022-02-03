class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =nums.size(); 
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int left=1;
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) 
                continue;
            int left = i+1,right=n-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0)
                    right--;
                else if(nums[i]+nums[left]+nums[right]<0)
                    left++;
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                     while(nums[left-1]==nums[left] && left<right)
                        left++;
                }
            }
        }
        return ans;
    }
};

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = [0]
Output: []
