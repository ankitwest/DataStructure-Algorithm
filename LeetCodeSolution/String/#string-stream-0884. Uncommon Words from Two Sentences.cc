
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m;
        vector<string> ans;
        stringstream a(s1); stringstream b(s2); string word;
        while(a >> word)
            m[word]++;

        while(b >> word)
            m[word]++;

        for(auto &x :m)
            if(x.second==1) ans.push_back(x.first);

        sort(ans.begin(),ans.end());
        return ans;
    }
};

Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
