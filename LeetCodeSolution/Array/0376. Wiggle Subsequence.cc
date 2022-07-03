class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up = 1; int down = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) {
                up = down + 1;
            }else if(nums[i]<nums[i-1]){
                down = up + 1;
            }
        }
        return max(up,down);
    }
};
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
Example 2:

Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).
