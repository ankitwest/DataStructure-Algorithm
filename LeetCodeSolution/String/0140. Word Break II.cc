//backtrack
class Solution1 {
    vector<vector<string>> result;
    
    void solve(int i,string s, vector<string>& wordDict,vector<string> &res){
        if(i==s.size()){
            result.push_back(res);
            return;
        }
        
        for(int k=i;k<s.size();k++){
            string str = s.substr(i,k-i+1);
            if(find(wordDict.begin(),wordDict.end(),str) != wordDict.end()){
                res.push_back(str);
                solve(k+1,s,wordDict,res);
                res.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(); vector<string> res;
        solve(0,s,wordDict,res);
        
        for(auto v:result){
            string ans = "";
            for(auto w:v){
                ans += w + " ";
            }
            ans.pop_back();
            res.push_back(ans);
        }
        return res;
    }
};


//dp
class Solution {
    unordered_map<string, vector<string>> dp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        if(dp.count(s)) 
            return dp[s];
        
        vector<string> result;
        for(string w : wordDict){
            int l = w.size();
            string firstHalf = s.substr(0, l);
            if(w == firstHalf){
                if(l == n)
                    result.push_back(w);
                else{
                    string secondHalf = s.substr(l);
                    vector<string> temp = wordBreak(secondHalf , wordDict);
                    for(string t : temp)
                        result.push_back(w + " " + t);
                }
            }
        }
        dp[s] = result;
        return result;
    }
};

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
