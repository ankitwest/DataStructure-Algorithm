

class Solution {
public:
    const int mod = 1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        set<long long> s(nums1.begin(),nums1.end());
        
        long long total = 0;  long long curr_diff = 0; 
        long long max_decrement = 0;
        for(int i=0;i<n;i++){
            curr_diff = abs(nums1[i] - nums2[i]);
            total += curr_diff;
            
            auto it = s.lower_bound(nums2[i]);
            if(it != s.begin())   max_decrement = max(max_decrement , curr_diff - abs(*prev(it) - nums2[i]));
            if(it != s.end())     max_decrement = max(max_decrement , curr_diff - abs(*it - nums2[i]));
        }
        return (total - max_decrement) % mod;
    }
};


Input: nums1 = [1,7,5], nums2 = [2,3,5]
Output: 3
Explanation: There are two possible optimal solutions:
- Replace the second element with the first: [1,7,5] => [1,1,5], or
- Replace the second element with the third: [1,7,5] => [1,5,5].
Both will yield an absolute sum difference of |1-2| + (|1-3| or |5-3|) + |5-5| = 3.
