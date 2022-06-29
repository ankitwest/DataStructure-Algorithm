//Approach-2 (Recursion + Memoization (i, j))
class Solution2 {
public:
    int m, n, N;
    int t[101][101];
    
    bool check(string s1, string s2, int i, int j, string s3) {
        if(i == n && j == m && (i+j) == N) 
            return true;
            
        if(t[i][j] != -1)
            return t[i][j];
        
        bool a = false, b = false;
        int k = i + j;
        if(s1[i]==s3[k]){
            a = check(s1, s2, i+1, j, s3);
        }
        if(s2[j]==s3[k]){
            b = check(s1, s2, i, j+1, s3);
        }
        
        return t[i][j] = a | b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        memset(t, -1, sizeof(t));
        
        if(m + n != N)
            return false;
        return check(s1,s2,0,0,s3);
    }
    
};

        // return t[i][j] = ((s1[i]==s3[i+j] && check(s1, s2, i+1, j, s3)) | (s2[j]==s3[i+j] && check(s1, s2, i, j+1, s3)));



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int N = s3.length();
        
        if(n + m != N)
            return false;
        
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++){
             for(int j=0;j<=m;j++){
                 if(i==0 and j==0)  t[i][j] = 1;
                 else if(i==0){
                     if(s2[j-1]==s3[i+j-1])
                         t[i][j] = t[i][j-1];
                 }
                 else if(j==0){
                     if(s1[i-1]==s3[i+j-1])
                         t[i][j] = t[i-1][j];
                 }
                 else if(s1[i-1]==s3[i+j-1] and s2[j-1]!=s3[i+j-1])
                     t[i][j] = t[i-1][j];
                 else if(s1[i-1]!=s3[i+j-1] and s2[j-1]==s3[i+j-1])
                     t[i][j] = t[i][j-1];
                 else if(s1[i-1]==s3[i+j-1] and s2[j-1]==s3[i+j-1])
                     t[i][j] = t[i-1][j] | t[i][j-1];
             }
        }
        
        return t[n][m];
    }
};

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
