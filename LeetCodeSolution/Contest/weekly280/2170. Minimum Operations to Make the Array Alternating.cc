class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int freqEven[100001]={0};
        int freqOdd[100001]={0};
         int n = nums.size();
        int maxi = nums[0];
         for(int i=0;i<n;i++){
            if(i%2==0) freqEven[nums[i]]++;
            else freqOdd[nums[i]]++;
             maxi = max(maxi,nums[i]);
        }
        
        int firstMaxEven=0; int freqfirstMaxEven=0;
        int secondMaxEven=0; int freqsecondMaxEven=0;
        
        int firstMaxOdd=0; int freqfirstMaxOdd=0;
        int secondMaxOdd=0; int freqsecondMaxOdd=0;
        
        
        for(int i=1;i<=maxi;i++){
            if(freqEven[i]>freqfirstMaxEven){
                secondMaxEven = firstMaxEven;
                freqsecondMaxEven = freqfirstMaxEven;
                
                firstMaxEven = i;
                freqfirstMaxEven = freqEven[i];
            }else if(freqEven[i]>freqsecondMaxEven){
                secondMaxEven = i;
                freqsecondMaxEven = freqEven[i];
            }
            
            if(freqOdd[i]>freqfirstMaxOdd){
                secondMaxOdd = firstMaxOdd;
                freqsecondMaxOdd = freqfirstMaxOdd;
                
                firstMaxOdd = i;
                freqfirstMaxOdd = freqOdd[i];
            }else if(freqOdd[i]>freqsecondMaxOdd){
                secondMaxOdd = i;
                freqsecondMaxOdd = freqOdd[i];
            }
            
        }
        
        if(firstMaxEven != firstMaxOdd)
            return n-freqfirstMaxEven-freqfirstMaxOdd;
        
        return min(n-freqfirstMaxEven-freqsecondMaxOdd,n-freqfirstMaxOdd-freqsecondMaxEven);
        
    }
};


