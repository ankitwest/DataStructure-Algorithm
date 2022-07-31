class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string word;
        stringstream iss(s);
        while (iss >> word)
            v.push_back(word);
      
        if (pattern.size() != v.size())
            return false;
        
        set<string> S; 
        unordered_map<char, string> m;
        
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            if (m.find(ch) != m.end()) {
                if (m[ch] != v[i])
                    return false;
            }else {
                // Check if the string is previously in set
                // If it is in set it means it is already mapped return false
                if (S.count(v[i]) > 0)
                    return false;
                // Other wise insert into map and set
                m[ch] = v[i];
                S.insert(v[i]);
            }
        }
        return true;
        

    }
};
