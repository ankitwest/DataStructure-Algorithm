class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        
        if(n==0 or k>n) return 0;
        
        unordered_map<char,int> m;
        for(auto ch:s) m[ch]++;
        
        int sub1 = 0; int sub2 = 0;
        for(int i=0;i<n;i++){
            if(m[s[i]]<k){
                string left = s.substr(0,i);
                string right = s.substr(i+1);
                sub1 = longestSubstring(left, k);
                sub2 = longestSubstring(right, k);
                break;
            }
            if(i==n-1)
                return n;
        }
        return max(sub1,sub2);
    }
};


Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
