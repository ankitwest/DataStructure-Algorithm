class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         int l=1,r=1; int ans = INT_MIN; int n = nums.size();
        
//         for(int i=0;i<n;i++){
//             l*=nums[i];
//             r*=nums[n-1-i];
//             ans = max(ans,max(l,r));
//             if(l==0) l=1;
//             if(r==0) r=1;
//         }
//         return ans;
        
        int maxProd = 1,minProd =1; int ans = INT_MIN;int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]<0)
                swap(maxProd,minProd);
            
            maxProd = max(maxProd*nums[i],nums[i]);
            minProd = min(minProd*nums[i],nums[i]);
            
            ans = max(ans,maxProd);
        }
        return ans;
    }
    };

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
