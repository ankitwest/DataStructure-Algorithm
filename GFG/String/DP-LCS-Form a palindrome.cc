
class Solution{
public:
vector<vector<int>> dp;
    int solve(int i,int j,string s){
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int ans = 0;
        if(s[i]==s[j])
            ans = solve(i+1,j-1,s);
        else
            ans = min(solve(i+1,j,s),solve(i,j-1,s)) + 1;
        
        return dp[i][j] = ans;
    }
    int findMinInsertions(string s){
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(0,n-1,s);
    }
    };
    
    Example 1:

Input:
abcd
Output:
3
Explanation:
Here we can append 3 characters in the 
beginning,and the resultant string will 
be a palindrome ("dcbabcd").
Example 2:

Input:
aba
Output:
0
Explanation:
Given string is already a pallindrome hence
no insertions are required.
    
    
class Solution{   
public:
vector<vector<int>> dp;
        int lcs(string a,string b,int n,int m){
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(i==0 or j==0)
                    dp[i][j] = 0;
                    
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
     int findMinInsertions(string s){
         string a = s; int n = a.size();
         string b = s; int m = b.size();
         reverse(b.begin(),b.end());
         int ans = lcs(a,b,n,m);
         return n - ans;
     }
};
