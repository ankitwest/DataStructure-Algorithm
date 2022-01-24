class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(),v.end());
        
        int i=(n-1)/2;
        int j=n-1;  int k=0;
        while(k<n){
            if(k%2==0) nums[k++] = v[i--];
            else nums[k++] = v[j--];
        }
    }
};

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.
  
  [4,5,5,6]
[5,6,4,5]
