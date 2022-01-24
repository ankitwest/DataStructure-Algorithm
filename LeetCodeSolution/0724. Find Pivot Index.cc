class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n),suf(n);
        pre[0]=nums[0]; suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suf[i] = suf[i+1]+nums[i];
        }
        
        // for index i=0
        if(suf[1]==0) return 0;
        
        for(int i=1;i<n-1;i++){
            if(pre[i-1]==suf[i+1]) return i;
        }
        // for index i=n-1
        if(pre[n-2]==0) return n-1;
        return -1;
    }
];
  
  TC - O)3N)
  
  Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
  
  
  [-1,-1,1,1,0,0]  ans = 4 and not 5
  
  
  
  
  TC - O(2N)
  
  
  class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;
        
        for(int i=0;i<n;i++){
            rightSum -= nums[i];
            if(leftSum==rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
  };
