class Solution{
public:
  int ss=0,tt=0;
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
        else   // considering all three operations on str1
            ans = min({rec(s,t,i-1,j),rec(s,t,i,j-1),rec(s,t,i-1,j-1)}) + 1;//remove , insert , replace
        
        return dp[i][j]=ans;
    }
    int editDistance(string s, string t) {
        ss = s.size(); tt = t.size();
        dp.resize(ss+1,vector<int>(tt+1,-1));
        
        return rec(s,t,ss,tt);
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
  
  
  
//   M-2
  
  
