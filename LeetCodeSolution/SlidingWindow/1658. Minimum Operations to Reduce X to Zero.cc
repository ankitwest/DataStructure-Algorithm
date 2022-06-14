class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int n = nums.size();
        int tot = accumulate(nums.begin(),nums.end(),0);
        int target = tot - x;
        int l=0; int ans = -1;  int sum = 0; 
        
        if(target<0) return -1;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            while(sum>target){
                sum -= nums[l];
                l++;
            }
            if(sum==target)
                ans = max(ans,(i-l+1));
        }
        if(ans==-1) return -1;
        return n - ans;
    }
};
nput: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
