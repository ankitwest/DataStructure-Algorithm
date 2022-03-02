class Solution
{
public:
    long long countStrings(string s){
        long long n = s.size();
        long long freq[26] = {0};
        for(auto c:s) 
            freq[c-'a']++;
        
        long long ans = 0;
        for(auto c:s) 
            ans += n-freq[c-'a'];
            
        ans /= 2;
        
        for(auto c:s) 
            if(freq[c-'a']>=2) {ans++; break;}
  
        return ans;
    }
};
Input: s = “geek”
Output: 6
Explanation: Following are the strings formed by doing exactly one swap
strings = [“egek”,”eegk”,”geek”,”geke”,”gkee”, “keeg”]
Therefore, there are 6 distinct possible strings.

Input: s = “ab”
Output: 1
