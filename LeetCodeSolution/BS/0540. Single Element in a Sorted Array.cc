class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l = 0,h = n-2; int ans = 0;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if((mid%2==0 and nums[mid]==nums[mid+1]) or (mid%2==1 and nums[mid]==nums[mid-1]))  //pattern is correct
                l = mid + 1;
            else 
                ans = mid,h = mid - 1;
        }
        return nums[ans];
    }
};
//before:first instance - at even index, second instance at odd index
//after: first instance - at odd index, second instance at even index
// [1]  l = 0, h = n-2;


Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
