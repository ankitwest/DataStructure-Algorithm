class Solution {
private:
    vector<int> prefix_fun(const string &str){
        int n = str.size();
        vector<int> lps(n);
        for(int i = 1; i < n; i++){
            int j = lps[i-1];
            while(j>0 and str[i] != str[j]){
                j = lps[j-1];
            }
            
            if(str[i] == str[j])
                j++;
            
            lps[i] = j;
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
      vector<int> lps = prefix_fun(needle);
           int j = 0;
         for(int i = 0; i < haystack.size(); i++) {
             if(haystack[i] == needle[j]){
                 j++;
             }else{
                 if(j){
                     j = lps[j-1];
                     i--;
                 }
             }
             
             if(j==needle.size())
                 return i - j + 1;
         }
        return -1;
    }
};


Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

