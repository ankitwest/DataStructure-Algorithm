

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = nums[0];
        int n = min(nums.size(),res.size());
        for(int i=0;i<n;i++){
            res[i] = nums[i][i] == '0' ? '1' : '0';
        }
        return res;
    }
};

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
