class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(auto &s : strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            m[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};


//improving TC
class Solution {
    string fun(string &s){
        vector<int> count(26,0);
        for(char c:s) count[c-'a']++;
        
        string code;
        for(auto i:count) code += i+'0';
        return code;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(auto &s : strs){
            m[fun(s)].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
