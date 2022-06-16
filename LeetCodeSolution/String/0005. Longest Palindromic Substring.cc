class Solution {
public:
     string longestPalindrome(string s) {
         int n = s.size();
         vector<vector<int>> dp(n,vector<int> (n,0));
         
         for(int i=0;i<n;i++)
             dp[i][i] = true;
         
         int start = 0; int len = 1;
         for(int gap=1;gap<n;gap++){
             for(int i=0;i<n-gap;i++){
                 int j = i + gap;
                 if(s[i] == s[j])
                 {
                     if(gap==1 or dp[i+1][j-1]==1)
                     {
                        dp[i][j] = 1;
                         if(len < j-i+1)
                            start = i, len = j - i + 1;
                     }
                        
                 }
             }
         }
         return s.substr(start,len);
     }
};

// "aaaa"
// "abcba"

class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.length();
         int start = 0; int maxlen = 1;
        for (int i = 0; i<n; i++) {
            int low = i;
            int high = i;
            while(low >= 0 and high < n and s[low] == s[high]) {
                int len = high - low + 1 ;
                if (len > maxlen) {
                    maxlen = high-low+1;
                    start = low;            
                }  
                low--;
                high++;
            }
            
            low = i;
            high = i+1;
            while(low >= 0 and high < n and s[low] == s[high]) {
                 int len = high - low + 1 ;
                if (len > maxlen) {
                    maxlen = high-low+1;
                    start = low;
                }
                low--;
                high++;
            }
        }
        return s.substr(start, maxlen);
    }
};


Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
