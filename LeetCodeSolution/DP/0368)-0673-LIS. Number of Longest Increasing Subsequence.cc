class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> cnt(n,1);
        
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] and  lis[j] + 1 > lis[i]){
                    lis[i] = lis[j] + 1;
                    cnt[i] = cnt[j];
                }else if(nums[i] > nums[j] and lis[j] + 1 == lis[i]){
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi,lis[i]);
        }
        
        // for(auto i:cnt) cout<<i<<" "; cout<<endl;
        
        int noOfLis = 0;
        for(int i=0;i<n;i++){
            if(lis[i] == maxi)
                noOfLis += cnt[i];
        }
        
        return noOfLis;
    }
};
