

class Solution2 {
public:
    int countSubstrings(string s) {
        int start,end,count=0; int n = s.size();
       for(int i=0;i<n;i++){
           //for odd length
           start=i; end=i;
           while(start>=0 and end<n and s[start]==s[end]) count++,start--,end++;
           
           //for even length
           start=i-1; end=i;
           while(start>=0 and end<n and s[start]==s[end]) count++,start--,end++;
       }
        return count;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));
        
        int ans = 0;
       for(int gap=0;gap<n;gap++){
           for(int i=0,j=gap;j<n;i++,j++){
               if(gap==0)
                   dp[i][j] = 1;
               else if(gap==1)
                   if(s[i]==s[j]) dp[i][j] = 1; else  dp[i][j] = 0;
               else
                   if(s[i]==s[j] and dp[i+1][j-1]==1) dp[i][j] = 1; //extreme same and inbetween palindrome
               ans += dp[i][j];
           }
       }
        return ans;
    }
};
