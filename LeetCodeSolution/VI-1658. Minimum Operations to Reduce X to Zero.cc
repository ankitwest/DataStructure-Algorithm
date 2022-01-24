
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l=0,r=0;
        int tot = accumulate(nums.begin(),nums.end(),0);
        int k = tot - x; int ans = -1;
        int sum = 0;
        
        if(k<0) return -1;
        
       while(r<n){
           sum += nums[r];
           if(sum==k)
               ans = max(ans,r-l+1);
           while(sum>k)
               sum-=nums[l],l++;
           if(sum==k)
               ans = max(ans,r-l+1);
           r++;
       } 
        if(ans==-1) return -1;
        
        return n-ans;
    }
];
  
  
  Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
  
  Input: nums = [5,6,7,8,9], x = 4
Output: -1
