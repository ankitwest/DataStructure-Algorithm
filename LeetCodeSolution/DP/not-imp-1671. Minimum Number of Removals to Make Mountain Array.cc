class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> lds(n,1);
        
        //inc
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    lis[i] = max(lis[i],lis[j]+1);
            }
        }
        //dec
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i])
                    lds[i] = max(lds[i],lds[j]+1);
            }
        }
        
        int longest = 1;
        for(int i=1;i<n-1;i++){
            if(lis[i]>1 and lds[i]>1)  // it has to be mountain
                longest = max(longest,lis[i]+lds[i]-1);  // for no repittion  of nums[i];
        }
        
        return n-longest;
    }
};

// similar both
class Solution2 {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(); vector<int> v;
        vector<int> lis(n,1);
        vector<int> lds(n,1);
        for(int i=0;i<n;i++){
            int idx = lower_bound(v.begin(),v.end(),nums[i]) - v.begin();
            if(idx==v.size()) v.push_back(nums[i]);
            else v[idx] = nums[i];
            lis[i] = v.size();
        }
        v.clear();
        for(int i=n-1;i>=0;i--){
            int idx = lower_bound(v.begin(),v.end(),nums[i]) - v.begin();
            if(idx==v.size()) v.push_back(nums[i]);
            else v[idx] = nums[i];
            lds[i] = v.size();
        }
         int longest = 1;
        for(int i=1;i<n-1;i++){
            if(lis[i]>1 and lds[i]>1)
                longest = max(longest,lis[i]+lds[i]-1);
        }
        return n - longest;
    }
};

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.
Example 2:

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
