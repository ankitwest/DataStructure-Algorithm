class Solution {
public:
    vector<int> dp;
    int solve(int i,string s,vector<string>& wordDict){
        if(i==s.size()){
            return true;
        }
        
        if(dp[i]!=-1)
            return dp[i];
        
        bool ans = false;
        for(int k=i;k<s.size();k++){
            string str = s.substr(i,k-i+1);
            if(find(wordDict.begin(), wordDict.end(), str) != wordDict.end()){
                if(solve(k+1,s,wordDict))
                    ans = true;
            }
        }
        return dp[i] = ans;
    }
 bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int i=0;
        dp.resize(n,-1);
        return solve(i, s, wordDict);
    }
};


Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
  
  
  
  
// class Solution2 {
// public:   // TC -  O(N^3)
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int len = s.size();
//         bool dp[len+1];
//         memset(dp,false,sizeof(dp));
//         dp[0] = true;
        
//         for(int i=1;i<=len;i++){
//             for(int j=1;j<=i;j++){
//                 int start = i-j; int len = j;
//                 string str = s.substr(start,len);
//                 if(find(wordDict.begin(),wordDict.end(),str) != wordDict.end() and dp[start])
//                 {
//                     dp[i] = true; 
//                 }
//             }
//         }
//         return dp[len];
//     }
// };

