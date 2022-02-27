class Solution {
public:
    int dp[14][(1<<14)-1];
    int help( vector<int> &v1,vector<int>& v2,int i,int mask){
        if (i >= v1.size()) return 0;
        
        int ans=INT_MAX;
        if(dp[i][mask]!=-1) 
            return dp[i][mask];
        
        for (int j = 0; j < v2.size(); j++){
            if(!(mask&(1<<j)))
                ans=min(ans, (v1[i]^v2[j]) + help(v1,v2,i+1,mask|(1<<j)) );
        }
        return dp[i][mask]=ans;
    }
    int minimumXORSum(vector<int>& v1, vector<int>& v2){
        memset(dp,-1,sizeof(dp));
        return help(v1,v2,0,0);
    }
};

Example 1:

Input: nums1 = [1,2], nums2 = [2,3]
Output: 2
Explanation: Rearrange nums2 so that it becomes [3,2].
The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.
Example 2:

Input: nums1 = [1,0,3], nums2 = [5,3,4]
Output: 8
Explanation: Rearrange nums2 so that it becomes [5,4,3]. 
The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.
