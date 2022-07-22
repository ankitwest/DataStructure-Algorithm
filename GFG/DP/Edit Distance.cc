class Solution{
public:
  vector<vector<int>> dp;
    int rec(string s, string t,int i,int j){
        if(i<0 or j<0) return INT_MAX;
        
        if(i==0) return j;
        if(j==0) return i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = 0;
        if(s[i-1]==t[j-1])
            ans = rec(s,t,i-1,j-1);
        else    // considering all three operations on str1
                //remove , insert , replace
            ans = 1 + min({rec(s,t,i-1,j),rec(s,t,i,j-1),rec(s,t,i-1,j-1)});
        
        return dp[i][j] = ans;
    }
  public:
    int editDistance(string s, string t) {
        int s_n = s.size(); int t_n = t.size();
        dp.resize(s_n+1,vector<int>(t_n+1,-1));
        
        return rec(s,t,s_n,t_n);
    }
};


Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
