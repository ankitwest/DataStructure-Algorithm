
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                return i+1;
        
        return n+1;
    }
};

https://leetcode.com/problems/first-missing-positive/

https://leetcode.com/problems/first-missing-positive/discuss/767105/Short-C%2B%2B-O(n)-time-O(1)-space-oror-Steps-explained

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
