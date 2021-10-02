class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k = k % nums.size();
         reverse(nums.begin(), nums.end());
         reverse(nums.begin(), nums.begin() + k);
         reverse(nums.begin() + k, nums.end());
    }
};




class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,0);
            for(int i = 0; i<n ;i++)
                ans[(i+k)%n] = nums[i];
        nums=ans;
    }
};





TLE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        while(k--){
            int temp = nums[nums.size()-1];
            for(int i = nums.size()-1; i>0 ;i--){
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
        }   
    }
};
