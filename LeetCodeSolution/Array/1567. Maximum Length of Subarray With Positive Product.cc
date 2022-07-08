class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int last_index = 0;int last_neg_index = -1;
        int neg = 0;
        for(int i=0;i<n;++i){
            if(nums[i] == 0){
                last_index = i+1;
                last_neg_index = -1;
                neg = 0;
            }else if(nums[i] < 0){
                if(last_neg_index == -1) last_neg_index = i;
                neg++;
            }
            
            
            if(neg%2==1) 
                maxi = max(maxi,i-last_neg_index);
            else if(neg%2==0)
                maxi = max(maxi,i-last_index+1);
            
        }
        return maxi;
    }
};
