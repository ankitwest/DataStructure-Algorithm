// Expected Time Complexity: O(N^2*n) 
// Expected Auxiliary Space: O(N^2)

class Solution0 {
    vector<string> ans;
    unordered_map<string,int> m;
    void solve(int idx,string s,string temp){
        if(idx==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        string prev = temp;
        for(int i=0;i<s.size();i++){
            string left = s.substr(0,i+1);
            string right = s.substr(i+1);
            if(m.count(left)){
                temp = temp + left + " ";
                solve(0,right,temp);
                temp = prev;
            }
        }
    }
public:    
    vector<string> wordBreak(int n, vector<string>& wordDict, string s){
        for(auto w :wordDict)
            m[w]++;
        solve(0,s,"");
        
        return ans;
    }
};



//backtrack
class Solution1 {
    vector<string> ans;
    unordered_map<string,int>freq;
    void solve(int i,string s,string temp)
    {
        if(i==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        string prev = temp;
        for(int k=i;k<s.size();k++){
            string str = s.substr(i,k-i+1);
            if(freq.count(str)){
                temp = temp + str + " ";
                solve(k+1,s,temp);
                temp = prev;
            }
        }
    }
public:
    vector<string> wordBreak(int n, vector<string>& wordDict, string s)
    {
        string temp="";
        for(auto it : wordDict) freq[it]++;
        solve(0,s,temp);
        
        return ans;
    }
};


//not good
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
