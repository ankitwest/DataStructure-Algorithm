


class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string &s,string &p,int i,int j){
        if(i<0 and j<0) return true;
        if(i<0 and j>=0) return false;
        
        if(i>=0 and j<0){
            for(int i1=0;i1<=i;i1++)
                if(s[i1]!='*') return false;
            return true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool ans;
        if(s[i]==p[j] or s[i]=='?')
            ans = solve(s,p,i-1,j-1);
        else if(s[i]=='*')
            ans = solve(s,p,i-1,j) or solve(s,p,i,j-1);
        
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        swap(s,p);
        int n = s.size(); int m = p.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(s,p,n-1,m-1);
    }
};


Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
  
  Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
    
    

    
    
    
    

// Tabulation
class Solution {
public:
    // make changes in this acc to 1 based indexing and then use this code in tabulation
//     bool solve(string &s,string &p,int i,int j){
//         if(i==0 and j==0) return true;
//         if(i==0 and j>0) return false;
        
//          if(i>0 and j==0){  
//             for(int i1=1;i1<=i;i1++)
//                 if(s[i1-1]!='*') return false;
//             return true;
//         }
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         bool ans;
//         if(s[i-1]==p[j-1] or s[i-1]=='?')
//             ans = solve(s,p,i-1,j-1);
//         else if(s[i-1]=='*')
//             ans = solve(s,p,i-1,j) or solve(s,p,i,j-1);
        
//         return dp[i][j] = ans;
//     }
    bool isMatch(string s, string p) {
        swap(s,p);
        int n = s.size(); int m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        dp[0][0] = true;
        for(int j=1;j<=m;j++){
            dp[0][j] = false;
        }
        
        for(int i=1;i<=n;i++){
            bool flag = true;
            for(int i1=1;i1<=i;i1++)
                if(s[i1-1]!='*'){ flag = false; break;}
            
            dp[i][0] = flag;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                bool ans = false;
                 if(s[i-1]==p[j-1] or s[i-1]=='?')
                    ans = dp[i-1][j-1];
                else if(s[i-1]=='*')
                    ans = dp[i-1][j] or dp[i][j-1];
        
                dp[i][j] = ans;
            }
        }
        return dp[n][m];
    }
};
