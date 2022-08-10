class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int low=INT_MAX;
        for(int i=0;i<n-1;i++)
            low = min(low,nums[i+1]-nums[i]);
        
        int high = nums[n-1]-nums[0];
        
        auto count2 = [&](int mid){
            int cnt = 0; int j=0;  // two pointer
            for(int i=0;i<n;i++){
                while(j<n and nums[j]-nums[i]<=mid)j++;
                j--;
                cnt += j-i;  // pairs
            }
            return cnt;
        };  
    
        auto count = [&](int mid)->int{ //check
            int cnt = 0; int j = 0;  

            for(int i=0;i<n;i++){
                int tar = nums[i]+mid;
                auto it = upper_bound(nums.begin()+i,nums.end(),tar) - nums.begin();
                cnt += it - (i+1);
            }
            return cnt;
        };
        
        while(low<high){
            int mid = (low+high)>>1;
            if(count(mid)>=k)
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }
};
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
