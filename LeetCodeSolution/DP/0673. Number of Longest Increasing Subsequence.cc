

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> count(n,1);
        
        int max_len = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(lis[i] < lis[j] + 1)
                        lis[i] = lis[j] + 1,count[i] = count[j];
                    else if(lis[i] == lis[j] + 1)
                        count[i] += count[j];
                }
            }
            max_len = max(max_len,lis[i]);
        }
        
        // for(auto i:count) cout<<i<<" "; cout<<endl;
        
        int noOfLis = 0;
        for(int i=0;i<n;i++){
            if(lis[i]==max_len)
                noOfLis += count[i];
        }
        
        return noOfLis;
    }
};
