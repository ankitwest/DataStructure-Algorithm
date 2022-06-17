class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0)return nums[0];
        
        if(n==1){
            if(k&1) return -1;
            else return nums[0];
        }
        
        if(k>n){
            int maxi = *max_element(nums.begin(),nums.end());
            return maxi;
        }else if(k==n){
            int maxi = *max_element(nums.begin(),nums.end()-1);
            return maxi;
        }else if(k<n){
            int maxi = 0;
            for(int i=0;i<k-1;i++){
                maxi = max(maxi,nums[i]);
            }
            maxi = max(maxi,nums[k]);
            return maxi;
        }
        return -1a
    }
};
