class Solution{
    public:
    int dp[101][101][101];
    int solve(int keys[],int freq[],int left,int right,int h){
        if(left>right)
            return 0;
        if(dp[left][right][h]!=-1)
            return dp[left][right][h];
            
        int ans=INT_MAX;
        
        for(int i=left;i<=right;i++){
            ans = min(ans,h*freq[i]+solve(keys,freq,left,i-1,h+1)+solve(keys,freq,i+1,right,h+1));
        }
        return dp[left][right][h] = ans;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        memset(dp,-1,sizeof(dp));
       return solve(keys,freq,0,n-1,1);
    }
 };


Example 2:


Input:
N = 3
keys = {10, 12, 20}
freq = {34, 8, 50}
Output: 142
Explaination: There can be many possible BSTs
     20
    /
   10  
    \
     12  
     
Among all possible BSTs, 
cost of this BST is minimum.  
Cost of this BST is 1*50 + 2*34 + 3*8 = 142
