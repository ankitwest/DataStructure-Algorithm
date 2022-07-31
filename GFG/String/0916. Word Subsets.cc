class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        const int char_set = 26; 
        vector<int> max_cnt(char_set);
        
        for(auto &w: words2){
            vector<int> cnt(char_set);
            for(auto &c: w){
                cnt[c-'a']++;
                max_cnt[c-'a'] = max(max_cnt[c-'a'],cnt[c-'a']);
            }
        }
        
        vector<string> ans;
        for(auto &w: words1){
            vector<int> cnt(char_set);
            for(auto &c: w){
                cnt[c-'a']++;
            }
            
            bool flag = true;
            for(int i=0;i<char_set;i++){
                if(max_cnt[i] > cnt[i]) {
                    flag = false; break;
                }
            }
            
            if(flag) ans.push_back(w);
        }
        return ans;
    }
};

// STRING trick 
// 1. Trie
// 2. 26 Alphabet
// 3. LIS LCS 
