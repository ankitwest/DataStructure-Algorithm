class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<int> v;
        int leftSum=0,rightSum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            leftSum+=nums[i];
            rightSum=sum-leftSum;
            int ans1 = nums[i]*(i+1)-leftSum;  int ans2 = rightSum-nums[i]*(n-i-1);
                ans = ans1+ans2;
            v.push_back(ans);
        }

        return v;
    }
};
