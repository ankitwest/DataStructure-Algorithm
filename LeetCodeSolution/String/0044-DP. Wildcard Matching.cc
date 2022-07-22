class Solution1 {
public:
    vector<vector<int>> dp;
    bool solve(string &pat,string &s,int i,int j){
        if(i<0 and j<0) return true;
        if(i<0 and j>=0) return false;
        
        if(j<0 and i>=0){
            for(int idx=0;idx<=i;idx++)
                if(pat[idx]!='*') return false;
            return true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool ans = false;
        if(pat[i]==s[j] or pat[i]=='?')
            ans = solve(pat,s,i-1,j-1);
        else if(pat[i]=='*')
            ans = solve(pat,s,i-1,j) or solve(pat,s,i,j-1);
        
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int s_n = s.size(); int p_n = p.size();
        dp.resize(p_n,vector<int>(s_n,-1));
        return solve(p,s,p_n-1,s_n-1);  // 0 based indexing   crt ans
    }
};


/*
"aab"
"c*a*b"
E:false

left c*a should also be exhausted 
and can only be with *
*/


class Solution2 {
public:
    vector<vector<int>> dp;
    // make changes in this acc to 1 based indexing and then use this code in tabulation
    bool solve(string &pat,string &s,int i,int j){
        if(i==0 and j==0) return true;
        if(i==0 and j>0) return false;
        if(j==0 and i>0){
            for(int idx=1;idx<=i;idx++)
                if(pat[idx-1]!='*') return false;
            return true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool ans = false;
        if(pat[i-1]==s[j-1] or pat[i-1]=='?')
            ans = solve(pat,s,i-1,j-1);
        else if(pat[i-1]=='*')
            ans = solve(pat,s,i-1,j) or solve(pat,s,i,j-1);
        
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        // swap(s,p);
        int s_n = s.size(); int p_n = p.size();
        dp.resize(p_n+1,vector<int>(s_n+1,-1));
        return solve(p,s,p_n,s_n);  // 1 based indexing
    }
};


// Tabulation
class Solution {
public:
    bool isMatch(string s, string pat) {
        int s_n = s.size(); int p_n = pat.size();
        vector<vector<bool>> dp(p_n+1,vector<bool>(s_n+1,false));
        
        dp[0][0] = true;
        for(int j = 1; j <= s_n; j++){
            dp[0][j] = false;
        }
        
        for(int i = 1; i <= p_n; i++){
            bool flag = true;
            for(int idx = 1; idx <= i; idx++){
                if(pat[idx-1] != '*'){ 
                    flag = false; 
                    break;
                }
            }
                
            dp[i][0] = flag;
        }
        
        for(int i = 1; i <= p_n; i++){
            for(int j = 1; j <= s_n; j++){
                bool ans = false;
                 if(pat[i - 1] == s[j - 1] or pat[i - 1] == '?')
                    ans = dp[i - 1][j - 1];
                else if(pat[i - 1] == '*')
                    ans = dp[i - 1][j] or dp[i][j - 1];
        
                dp[i][j] = ans;
            }
        }
        return dp[p_n][s_n];
    }
};
