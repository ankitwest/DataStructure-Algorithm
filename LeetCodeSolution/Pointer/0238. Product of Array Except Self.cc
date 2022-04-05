


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); vector<int> res(n,0);
        vector<int> leftProd(n,1);vector<int> rightProd(n,1);
        for(int i=0;i<n-1;i++){
            leftProd[i+1] = leftProd[i]*nums[i];
        }
        for(int i=n-1;i>=1;i--){
            rightProd[i-1] = rightProd[i]*nums[i];
        }
         for(int i=0;i<n;i++){
             res[i] = leftProd[i]*rightProd[i];
         }
        return res;
    }
};

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
