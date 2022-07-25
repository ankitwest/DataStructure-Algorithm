class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(); 
        int cnt = 0; int ans = 0;
        int l = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt++;
            
            while(l<i and cnt>1){
                if(nums[l] == 0) cnt--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans - 1;
    }
};
