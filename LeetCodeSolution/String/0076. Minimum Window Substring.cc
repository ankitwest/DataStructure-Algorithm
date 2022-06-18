class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(); int m = t.size();
        unordered_map<char,int> mp;
        for(auto ch:t) mp[ch]++;
        int count = mp.size();
        
        int i=0,l=0; int len = INT_MAX; 
        int start = 0;
        while(i<n){
            mp[s[i]]--;
            if(mp[s[i]]==0) count--;
            
            while(count==0){
                if(i-l+1 < len) len = i-l+1, start = l;
                
                mp[s[l]]++;
                if(mp[s[l]]>0) count++;
                l++;
            }
            i++;
        }
        
        string ans = "";
        if(len!=INT_MAX) 
            ans = s.substr(start,len);
        return ans;
    }
};


Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
