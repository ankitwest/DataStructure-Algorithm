class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        long long ans = 0;
         
        for(int i=0;i<n;i++){
            if(mp.find(s[i]) == mp.end())
                ans += (i+1) * (n-i);
            else 
                ans += (i-mp[s[i]]) * (n-i);
            mp[s[i]] = i;
        }
        return ans;
    }
};


// This is similar to 2063. Vowels of All Substrings.

// From that problem, we use the fact that each character appears in (i + 1) * (n - i) substrings. However, it does not contribute to the appeal of substrings on the left that already include that character. For example, for string "abcab", the second 'a' character contributes to the appeal of 6 substrings:

// "abca" and "abcab" (first 'a' character is already counted)
// "bca" and "bcab"
// "ca" and "cab"
// "a" and "ab"
// To exclude previously counted substrings, we just track the previous (prev) position of s[i] character. So, the final formula is (i - prev[ch]) * (n - i).
