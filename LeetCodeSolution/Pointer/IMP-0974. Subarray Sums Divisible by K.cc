class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0; int sum=0; int n = nums.size();
        unordered_map<int,int> m;
        m.insert({0,1});
        
        for(int i=0;i<n;i++){
            sum = ((sum + nums[i]) % k + k) % k;
            // if(sum<0) sum += k;
            if(m.find(sum)!=m.end()) 
                ans += m[sum%k];
            m[sum%k]++;
        }
        return ans;
    }
    };

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
