


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

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
