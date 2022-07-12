//Moore Voting Algorithm
class Solution0 {
public:
    int findSpecialInteger(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int prev = -1;
    
        for(int num : nums){
            if(num == prev){
                cnt++;
            }else{
                cnt = 1;
                prev = num;
            }
            if(cnt>n/4) return num;
        }
        return -1;
    }
};
class Solution1 {
public:
    int findSpecialInteger2(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int prev = -1;
        
        for(int num : nums){
            if(num == prev){
                cnt++;
            }
            else if(cnt==0){
                cnt = 1;
                prev = num;
            }
            else{
                cnt--;
            }
        }
        for(int num : nums)
            if(num == prev) cnt++;
        
        if(cnt > n/4) return prev;
        return -1;
    }
};

class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos = {nums[n/4], nums[n/2], nums[3*n/4]};
        for(auto num : pos){
            auto start = lower_bound(nums.begin(),nums.end(),num);
            auto end   = upper_bound(nums.begin(),nums.end(),num);
            
            if(end-start > n/4)
                return num;
        }
        return -1;
    }
};


/*
Because it's guaranteed that only one number will appear more than 25% times, that number will definitely appear at one of the three positions in the array: quarter, half, and three quarters. We see them as candidates, and then using binary search to check each of them.

Time complexity: O(logn)
*/




