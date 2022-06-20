class Solution11 {
    vector<string> result;
    unordered_map<string,int>freq;
    void solve(int i,string s, vector<string>& wordDict,string res)
    {
        if(i==s.size()){
            res.pop_back();
            result.push_back(res);
            return;
        }
        
        for(int k=i;k<s.size();k++){
            string str = s.substr(i,k-i+1);
            if(freq.count(str)){
                solve(k+1,s,wordDict,res + str + " ");
            }
        }
    }
public:
    vector<string> wordBreak(int n, vector<string>& wordDict, string s)
    {
        string res="";
        for(auto it : wordDict) freq[it]++;
        solve(0,s,wordDict,res);
        
        return result;
    }
};



// with memoization
class Solution {
    unordered_map<string, vector<string>> dp;
public:
    vector<string> wordBreak(int n, vector<string>& wordDict, string s)
    {
         n = s.size();
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
                    vector<string> temp = wordBreak(secondHalf.size(), wordDict, secondHalf);
                    for(string t : temp)
                        result.push_back(w + " " + t);
                }
            }
        }
        dp[s] = result;
        return result;
    }
};

Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given 
sentences are present in the dictionary.
