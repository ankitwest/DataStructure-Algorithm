class Solution1 { //tle in extreme tc
    int dp[1001][1001];
    int solve(int i,int j,string s,string t){
        if(i==0 and j==0)
            return 1;
        if(j==0)
            return 1;
        if(i==0)
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = 0;
        if(s[i-1]==t[j-1])
            ans += solve(i-1,j-1,s,t) + solve(i-1,j,s,t);
        else
            ans += solve(i-1,j,s,t);
        
        return dp[i][j] = ans;
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int n = s.size(); int m = t.size();
        return solve(n,m,s,t);
    }
};


class Solution {
public:
    const int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n = s.size(); int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<=n;i++)  dp[i][0] = 1;
        // for(int j=1;j<=m;j++)  dp[0][j] = 0;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0)
                    dp[i][j] = 1;
                else if(i==0 and j>0)
                    dp[i][j] = 0;
                else{
                    if(s[i-1]==t[j-1]) 
                        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                    else 
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
//either use MOD or use unsigned int or use double for extreme one




class Solution3 {
public:
    int numDistinct(string s, string t) {
        int n = s.size(); int m = t.size();
        
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        prev[0] = curr[0] = 1;  //for every j = 0 we put value 1; first value of these array
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) 
                    curr[j] = prev[j-1] + prev[j];
                else 
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return prev[m];
    }
};

class Solution4 {
public:
    int numDistinct(string s, string t) {
        int n = s.size(); int m = t.size();
        
        vector<int> prev(m+1,0);
        prev[0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]) 
                    prev[j] = prev[j-1] + prev[j];
            }
        }
        return prev[m];
    }
};


Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit


