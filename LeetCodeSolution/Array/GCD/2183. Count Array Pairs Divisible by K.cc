class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<long long,long long>m;
        long long ans = 0; int n = nums.size();
        for(int i=0;i<n;i++){
            long long gcd_i = gcd(nums[i], k);
            for(auto &[gcd_j, cnt] : m){
                if(gcd_i * gcd_j % k == 0)
                    ans += cnt;
            }
            m[gcd_i]++;
        }
        return ans;
    }
};


Input: nums = [1,2,3,4,5], k = 2
Output: 7
Explanation: 
The 7 pairs of indices whose corresponding products are divisible by 2 are
(0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4).
Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.
Other pairs such as (0, 2) and (2, 4) have products 3 and 15 respectively, which are not divisible by 2. 
