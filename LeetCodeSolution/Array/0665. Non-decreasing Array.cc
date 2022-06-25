class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(); int cnt = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                 cnt++;
                if(cnt>1) return false;
                if(i-1<0 or nums[i-1]<=nums[i+1]) 
                    nums[i] = nums[i+1];
                else 
                   nums[i+1] = nums[i];
            }
        }
        return true;
    }
};
/*
Case 1:
     7
     /\    4
    /  \  /
   /    \/
  /      3
 1
 
Case 2:

               9
              /
  7          /
  /\        /
 /  \      /
/    \    /
4     \  /
       \/
       3(i)
       
[4,2,3]
[4,2,1]
[1,4,1,2]
[3,4,2,3]  

Output
true
false
true
false
       */




Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.

