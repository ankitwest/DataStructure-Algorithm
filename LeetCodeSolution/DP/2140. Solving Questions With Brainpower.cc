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



class Solution {
public:
    long long n;
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<long long> dp(n,-1);
        
        dp[n-1] = questions[n-1][0];    // in recusrion i was going from 0 to n-1 which is top down approah 
        // so in bottom up we will go from n-1 to 0 & and our base case n-1 is already calculated;
        
        for(int ind=n-2;ind>=0;ind--){
            long long take = questions[ind][0];
            if(ind+questions[ind][1]+1<n) take += dp[ind+questions[ind][1]+1];
            
            long long notTake = 0 + dp[ind+1]; 
            
            dp[ind] = max(take,notTake);
        }
        
        return dp[0];
    }
};


Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
