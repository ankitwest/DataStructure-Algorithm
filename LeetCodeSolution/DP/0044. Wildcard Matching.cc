


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
