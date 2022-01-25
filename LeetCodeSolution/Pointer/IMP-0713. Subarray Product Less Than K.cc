class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        
        int start=0;
        int count=0; int pro = 1;
        for(int end=0;end<n;end++){
            pro *= nums[end];
            while(start<n and pro>=k)
                pro/=nums[start],start++;
            
            if(pro<k)
            count += end-start+1;
        }
        return count;
    }
    };
    
    
    
    Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
