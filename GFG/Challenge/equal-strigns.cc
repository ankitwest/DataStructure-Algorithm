Swap a character of S with a character of T.
Swap any two character of S.
swap any two character of T.

Input: S = abcb , T = bbca 
Output: YES
Explanation:
In the string T , if we swap 'b' at index 0
with 'a' at index 3 then S and T will be same.  

Input: S = abcba , T = bbcca
 Output: NO
Explanation:
We can see that it is not possible
to make S and T equal.
  
  
  

class Solution {
  public:
    bool isEqual(string s, string t) {
        map<char,int> m;
        for(auto ch:s) m[ch]++;
        for(auto ch:t) m[ch]++;
        
        for(auto x:m) if(x.second&1) return 0;
        return 1;
    }
};
