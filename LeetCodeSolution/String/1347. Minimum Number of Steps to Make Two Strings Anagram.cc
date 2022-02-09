

class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> ms,mt;
        for(auto c:s) ms[c]++;
        for(auto c:t) mt[c]++;
        
        int ans=0;
        for(auto [x,y]:ms){
            if(y>mt[x])
                ans += y-mt[x];
        }
        return ans;
    }
};

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
