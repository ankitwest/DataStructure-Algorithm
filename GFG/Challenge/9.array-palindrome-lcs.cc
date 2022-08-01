class Solution {
    vector<vector<int>> dp;
    int solve(vector<int>& a,vector<int>& b,int i,int j){
        if(i==0 and j==0)
            return 0;
        if(i==0)
            return 0;
        if(j==0)
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = 0;
        if(a[i-1]==b[j-1])
            ans = 1 + solve(a,b,i-1,j-1);
        else
            ans = max(solve(a,b,i-1,j), solve(a,b,i,j-1) );
            
        return dp[i][j] = ans;
    }
  public:
    int miniChange(vector<int>& a) {
        vector<int> b = a; int n = a.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        reverse(b.begin(),b.end());
        return n - solve(a,b,n,n);
    }
};
