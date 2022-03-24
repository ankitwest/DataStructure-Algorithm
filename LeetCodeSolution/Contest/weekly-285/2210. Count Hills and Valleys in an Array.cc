class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0; int n = nums.size();
        for(int i=1;i<n-1;i++){
            int mid = nums[i];
            int left = i-1; int right = i+1;
            while(left>=0 and nums[left]==mid) left--;
            while(right<n and nums[right]==mid) right++;
            if(left<0 or right>=n) continue;
            
            int l = nums[left]; int r = nums[right];
            if((mid>l and mid>r) or (mid<l and mid<r))ans++;
                // {ans++;cout<<mid<<endl;}
            i = right-1;
        }
        return ans;
    }
};
