
class Solution {
public:   // TC - O(N)
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0); int k=n-1;
        int i=0,j=n-1; 
        while(i <= j){
            if(abs(nums[i]) > abs(nums[j])){
                ans[k] = nums[i] * nums[i];
                k--,i++;
            }else{
                ans[k] = nums[j]*nums[j];
                k--,j--;
            }
        }
        return ans;
    }
};


Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
