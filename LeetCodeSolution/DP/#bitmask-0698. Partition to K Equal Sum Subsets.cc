

// class Solution {
// public:
//    bool helper(int idx,vector<int>&nums,int curr,int tar,int k,vector<bool>&vis){
//         if(k==0)
//             return true;
//         if(curr==tar)
//             return helper(0,nums,0,tar,k-1,vis);
        
        
//         for(int i=idx;i<nums.size();i++){
//             if(!vis[i] and curr+nums[i]<=tar){
//                 vis[i]=true;
//                 if(helper(i+1,nums,curr+nums[i],tar,k,vis))return true;
//                 vis[i]=false;
//             }
//         }
//         return false;
//     }
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<bool> vis;
//         vis.resize(n,false);

//         if(k>n) return false;
//         if(k==1) return true;
        
//         int sum = accumulate(nums.begin(),nums.end(),0);
//         if(sum%k!=0) return false;
//         int curr = 0; int cnt = 0;
//         return helper(0,nums,0,sum/k,k,vis);
//     }
// };



// bit masking approach
class Solution {
public:
    int all = 0; int n=0;
    vector<int> memo;
    bool solve(vector<int>& nums,int k,int mask,int curr,int sum){
        if(curr == sum){
            k--; curr=0;
        }
        
        if(curr>sum or k<0) return false;
        
        if(mask == all){
            return k==0 and curr==0;
        }
        
        if(memo[mask] != -1) return memo[mask];
        
        bool ans = false;
        for(int i=0;i<n;i++){
            if((mask & (1 << i)) == 0) 
                ans = ans || solve(nums, k, mask | (1 << i), curr+nums[i],sum);
        }
        return memo[mask] = ans;
    }
    
     bool canPartitionKSubsets(vector<int>& nums,int k) {
         n = nums.size();
          int sum = accumulate(nums.begin(),nums.end(),0);
         if(sum%k!=0) return false;
         
         memo.resize(1<<n,-1);
         int mask=0; all = (1<<n)-1;
         
         return solve(nums,k,mask,0,sum/k);
     }
};
