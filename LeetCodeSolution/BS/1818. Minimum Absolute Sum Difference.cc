

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
