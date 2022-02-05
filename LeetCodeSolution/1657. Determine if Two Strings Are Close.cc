


class Solution {
public:
    bool closeStrings(string word1, string word2) {
       vector<int> freq1(26,0);
       vector<int> freq2(26,0);
        
        for(auto c:word1){
            freq1[c-'a']++;
        }
        for(auto c:word2){
            if(freq1[c-'a']==0) return false;
            freq2[c-'a']++;
        }
        
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        return freq1==freq2;
    }
};

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
