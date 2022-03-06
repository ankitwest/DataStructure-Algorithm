class Solution {
public:
    long long gcd2(long long x,long long y) {
        return (x==0)?y:(gcd(x,y%x));
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            long long y = nums[i];
            while(ans.size()>0 and gcd2(y,ans.back())>1){
                long long x = ans.back();
                y = (x*y)/gcd2(x,y);
                ans.pop_back();
            }
            ans.push_back(y);
        }
        return ans;
    }
};

// while loop 

Input: nums = [6,4,3,2,7,6,2]
Output: [12,7,6]
Explanation: 
- (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
- (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
- (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
- (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [12,7,6].
Note that there are other ways to obtain the same resultant array.
