Bottom Up - Recursive Memoization Approach

class Solution{
    public:
    vector<vector<int>> dp;
    int rec(string &str1, string &str2,int i,int j){
        if(i<0 or j<0)return 0;
        
        if((i==0 or j==0) and (str1[i]==str2[j])) return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int ans=0;
        if(str1[i]==str2[j])
            ans = rec(str1,str2,i-1,j-1)+1;
        else
            ans = max(rec(str1,str2,i,j-1),rec(str1,str2,i-1,j));
            
        return dp[i][j] = ans;
    }
    int build_bridges(string str1, string str2)
    {
       int n1 = str1.size(); int n2 = str2.size();
       dp.resize(n1,vector<int>(n2,-1));
      return rec(str1,str2,n1-1,n2-1);
    }
};







 int build_bridges(string str1, string str2)
    {
        int n1 = str1.size(); int n2 = str2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        for(int i=0;i<=n1;i++)
            dp[i][0] = 0;
        for(int j=0;j<=n2;j++)
            dp[0][j] = 0;
    
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }

