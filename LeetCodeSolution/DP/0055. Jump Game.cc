
class Solution {
public:
     bool canJump(vector<int>& nums) {
         int n = nums.size();
         int maxReachable = 0; int curr=0;
         
       for(int i=0;i<n;i++){
           if(maxReachable<i) return false;
           maxReachable = max(maxReachable,nums[i]+i);
       }
         return true;
    }
};



// M-2  recursion

class Solution {
public:
    bool jump(vector<int>& nums,int l) {
        if(l==0) return true;
        
        for(int i=l-1;i>=0;i--){
            if(nums[i]>=l-i)
                return jump(nums,i);
        }
            return false;
    }  
    
    bool canJump(vector<int>& nums){
        int l=nums.size();
        if(jump(nums,l-1))
            return true;
        else return false;
    }
};
