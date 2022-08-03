class Solution1 {
    unordered_map<string,int>freq;
    vector<int> dp;
public:
    int solve(int i,string s,vector<string>& wordDict){
        if(i==s.size()){
            return true;
        }
        
        if(dp[i]!=-1)
            return dp[i];
        
        bool ans = false;
        for(int k=i;k<s.size();k++){
            string str = s.substr(i,k-i+1);
                if(freq.count(str)){
                    if(solve(k+1,s,wordDict))
                        ans = true;
                }
        }
        return dp[i] = ans;
    }
 bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        for(auto it : wordDict) freq[it]++;
        int i = 0;
        dp.resize(n,-1);
        return solve(i, s, wordDict);
    }
};



word-break2.cc

// with hashing search
class Solution { 
    vector<string> result;
    unordered_map<string,int>freq;
    void solve(int i,string& s, vector<string>& wordDict,string& res){
        if(i==s.size()){
            res.pop_back();
            result.push_back(res);
            return;
        }
        
        string prev = res;
        for(int k=i;k<s.size();k++){
            string str = s.substr(i,k-i+1);
            if(freq.count(str)){
                res = res + str + " ";
                solve(k+1,s,wordDict,res);
                res = prev;
                // solve(k+1,s,wordDict,res + str + " ");
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(); string res="";
        for(auto it : wordDict) freq[it]++;
        solve(0,s,wordDict,res);
        
        return result;
    }
};








