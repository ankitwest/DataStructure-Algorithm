class WordFilter {
public:
    unordered_map<string,int>m;
    WordFilter(vector<string>& words) {
        for(int k=0;k<words.size(); k++){
            auto word = words[k];
            for(int i=1;i<=word.size();i++){
                string p = word.substr(0,i);
                for(int j=0;j<word.size();j++){
                    string s = word.substr(j);
                    string sub = p + "#" + s;
                    m[sub] = k;
                }
            }
        }
    }
    // abc
    int f(string prefix, string suffix) {
        string str = prefix + "#" + suffix;
        if(m.find(str) != m.end()) return m[str];
        return -1;
    }
};
Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]

Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".

At most 15000 calls will be made to the function f.
