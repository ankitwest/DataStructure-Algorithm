class Solution {
public:
    long long n;
    long long solve(long long ind,vector<vector<int>>& questions,vector<long long> &dp){
        if(ind == n-1)
            return questions[ind][0];
        if(ind >= n)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        long long take = questions[ind][0] + solve(ind + questions[ind][1] + 1 , questions,dp);
        
        long long notTake = 0 + solve(ind+1,questions,dp);
        
        return dp[ind]=max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<long long> dp(n,-1);
        return solve(0,questions,dp);
    }
};
