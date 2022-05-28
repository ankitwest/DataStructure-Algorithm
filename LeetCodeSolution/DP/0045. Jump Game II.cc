//better

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReachable = 0; int jump=0; int curr=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(maxReachable<i) return -1;
            maxReachable = max(maxReachable,nums[i]+i);
            
            if(curr==i){
                if(i==n-1) continue;
                jump++;
                curr=maxReachable;
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
