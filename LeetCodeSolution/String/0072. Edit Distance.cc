class Solution {
public:
    vector<vector<int>> dp;
    int solve(string s1, string s2,int i,int j){
        if(i==0 and j==0)
            return 0;
        if(i==0)
            return j;
        if(j==0)
            return i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s1[i-1] == s2[j-1])
            dp[i][j] = solve(s1,s2,i-1,j-1);
        else
            dp[i][j] = 1 + min({solve(s1,s2,i-1,j) , solve(s1,s2,i,j-1) , solve(s1,s2,i-1,j-1)});
        
        return dp[i][j];
    }
    int minDistance(string s1, string s2) {
        int n = s1.size(); int m = s2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,n,m); 
        // n and m  (1-based indexing) bcoz it is eady to convert it into tabulation
        // n-1 and m-1 (0-based indexing) 
    }
};


class Solution2 {
public:  
    int minDistance(string s1, string s2) {
        int n = s1.size(); int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)
            dp[i][0] = i;
        for(int j=0;j<=m;j++)
            dp[0][j] = j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = 1 + min({dp[i-1][j] , dp[i][j-1] , dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};

class Solution3 {
public:  
    int minDistance(string s1, string s2) {
        int n = s1.size(); int m = s2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        for(int j=0;j<=m;j++)  //for every i=0 
            prev[j] = j;
        
        for(int i=1;i<=n;i++){
            curr[0] = i;     //for every j=0 
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    curr[j] = prev[j-1];
                else 
                    curr[j] = 1 + min({prev[j] , curr[j-1] , prev[j-1]});
            }
            prev = curr;
        }
       
        return prev[m];
    }
};

