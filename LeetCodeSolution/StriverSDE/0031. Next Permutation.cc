class Solution {
    void reverseFun(vector<int> &nums,int i,int j){
        while(i<=j){
            swap(nums[i],nums[j]);
            i++,j--;
        }
        return;
    }
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
            // reverseFun(nums,0,n-1);
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
        // reverseFun(nums,peakInd+1,n-1);
        reverse(nums.begin()+peakInd+1,nums.end());
        
    }
};
