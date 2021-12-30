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
