class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(); int sum=0;
        for(int i=0;i<n;i++){
             sum = (sum+nums[i])%p;
         }
        int req = sum%p;
        if(req==0) return 0;
        
        unordered_map<int,int> m;  int curr=0; int ans=n;
        m[0]=-1;
        for(int i=0;i<n;i++){
            curr = (curr+nums[i])%p;
            int need = (curr-req+p)%p;
            
            if(m.find(need)!=m.end()){
                ans = min(ans,i-m[need]);
            }
            m[curr]=i;
        }
        return ans==n?-1:ans;
    }
    };
    
    Example 1:
    

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
