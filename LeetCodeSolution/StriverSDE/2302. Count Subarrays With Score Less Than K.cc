#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        vector<long long> pre(n+1,0);
        for(ll i=0;i<n;i++){
            pre[i+1] = pre[i] + nums[i];
        }
        
        long long len = 1, l = 0, cnt =0;
         for(ll i=0;i<n;i++){
            long long len = i-l+1;
            long long curr = pre[i+1]-pre[l];
             while((len*curr)>=k){
                 l++;       
                 len = i-l+1;
                 curr = pre[i+1]-pre[l];
             }
             if(len*curr<k)
                 cnt+=len;
             // cout<<cnt<<" "<<i<<endl;
         }
        // cout<<endl;
        return cnt;
    }
};

Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.
