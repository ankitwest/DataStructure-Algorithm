// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
     vector<vector<int>> dp;
    int solve(int egg,int n){
        if(n<=2) return n;
        if(egg==1) return n;
         
        
        if(dp[egg][n]!=-1)
            return dp[egg][n];
        
        int ans = INT_MAX;
        for(int i=1;i<=n;i++){
            int curr = 1 + max(solve(egg,n-i), solve(egg-1,i-1));
            ans = min(ans, curr);
        }
        
        return dp[egg][n] = ans;
    }
    int eggDrop(int n, int k) 
    {
        int egg = n;
        n = k;

        dp.resize(egg+1,vector<int> (n+1,-1));
        solve(egg,n);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
