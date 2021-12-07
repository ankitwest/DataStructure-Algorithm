// Leetcode

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        bool dp[len+1];
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        for(int i=1;i<=len;i++){
            for(int j=1;j<=i;j++){
                if(find(wordDict.begin(),wordDict.end(),s.substr(i-j,j)) != wordDict.end() and dp[i-j]){
                    dp[i] = true; 
                }
            }
        }
        return dp[len];
    }
};

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
