//better
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // int maxReachable = 0; //for 0 based indexing
        // int jump = 0; int curr = 0;
        
        int maxReachable = nums[0] + 0;  //for 1 based indexing
        int jump = 1; int curr = nums[0] + 0;
        
        for(int i=1; i<n; i++){
            if(maxReachable < i) return -1;
            maxReachable = max(maxReachable,nums[i]+i);
            
            if(curr==i){
                if(i==n-1) continue;
                jump++;
                curr = maxReachable;
            }
        }
        return jump;
    }
};





// M-2
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int maxIndexReachable = nums[0];
        int ans=1; int lim=nums[0];
        for(int i=1;i<n;i++){
            if(i>lim){
                 ans++;
                lim = maxIndexReachable;
            }
            maxIndexReachable = max(maxIndexReachable,i+nums[i]);
        }
        return ans;
    }
};
