// 131. Palindrome Partitioning I
class Solution {
    vector<vector<string>> ans;
    vector<string> v;
    bool isPalindrome(string &s,int i,int j){
        while(i <= j)
            if(s[i++]!=s[j--]) return false;
        return true;
    }
    
    
    void func(string &s,int i)
    {
        if(i==s.size()){
            ans.push_back(v);
            return ;
        }
        
        for(int k=i;k<s.size();k++){
            if(isPalindrome(s,i,k)){
                v.push_back(s.substr(i,k-i+1));
                func(s,k+1);
                v.pop_back();
            }
        }
        return ;
    }
    
    
public:
    vector<vector<string>> partition(string s) {
        func(s,0);
        return ans;
    }
};

// 132. Palindrome Partitioning II

class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string &s,int i,int j){
        while(i <= j)
            if(s[i++]!=s[j--]) return false;
        return true;
    }
    
    int solve(string s,int i,int j){
        if(i>=j) return 0;
        
        if(isPalindrome(s,i,j)) return 0;
        
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(s,i,k)){
                int temp = 1 + solve(s,k+1,j);
                ans = min(ans, temp);
            }
        }
        
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1);
    }
};

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
