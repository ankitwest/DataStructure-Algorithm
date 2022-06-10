class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string &s,int i,int j){
        while(i<=j)
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
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
