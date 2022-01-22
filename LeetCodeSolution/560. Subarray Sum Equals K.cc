class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> m;
        int sum = 0; int n = nums.size(); int ans = 0;
        
        for(int i=0;i<n;i++){
            m[sum]++;
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()) ans += m[sum-k];
        }
        return ans;
    }
};


Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
  
  
  
  -1,1,0  -> 0  ans = 3
  [-1,-1,1] -> 0  ans = 1
