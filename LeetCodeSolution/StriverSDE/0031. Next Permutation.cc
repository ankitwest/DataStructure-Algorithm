class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int peakInd = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                peakInd = i; break;
            }
        }
        if(peakInd == -1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        int swapInd = peakInd+1;
        for(int i=n-1;i>peakInd;i--){
            if(nums[peakInd]<nums[i]){
                swapInd = i; break;
            }
        }
        
        swap(nums[swapInd],nums[peakInd]);
        sort(nums.begin()+peakInd+1,nums.end());
    }
};
