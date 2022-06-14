// Recursion and Memoization ; Top Down Approach

class Solution1 {
public:
    int n,m;
    int solve(vector<vector<int>>& dungeon,int i,int j,vector<vector<int>> &dp){
        if(i==n or j==m)
            return 1e9;
        if(i==n-1 and j==m-1)
            return dungeon[i][j]<=0?abs(dungeon[i][j])+1:1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int right = solve(dungeon,i,j+1,dp);
        int down =  solve(dungeon,i+1,j,dp);
        int minHealth = min(down,right) - dungeon[i][j];
        
        if(minHealth<=0) minHealth = 1;
        
        return dp[i][j] = minHealth;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size(); m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        
        return solve(dungeon,0,0,dp);
    }
};


https://github.com/ankitwest/DataStructure-Algorithm/blob/main/GFG/biddano.cc

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        
         if(dungeon[n-1][m-1]<=0)  dp[n-1][m-1] = abs(dungeon[n-1][m-1]) + 1;
         else dp[n-1][m-1] = 1;
        
        for(int i=n-2;i>=0;i--){
            dp[i][m-1] = dp[i+1][m-1]-dungeon[i][m-1];
            if(dp[i][m-1]<=0) dp[i][m-1] = 1;
        }
        for(int j=m-2;j>=0;j--){
            dp[n-1][j] = dp[n-1][j+1]-dungeon[n-1][j];
            if(dp[n-1][j]<=0) dp[n-1][j] = 1;
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j]; 
                if(dp[i][j]<=0) dp[i][j] = 1;
            }
        }
        return max(1,dp[0][0]);
    }
};



















class Solution {
public:
    int n,m;
    
    int solve(vector<vector<int>>& dungeon,int i,int j,vector<vector<int>> &dp){
        if(i==n or j==m)
            return 1e9;
        if(i==n-1 and j==m-1)
            return dungeon[i][j]<=0?-dungeon[i][j]+1:1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int right = solve(dungeon,i,j+1,dp);
        int down =  solve(dungeon,i+1,j,dp);
       
        int minHealth = min(down,right) - dungeon[i][j];
        minHealth = max(1,minHealth);
        return dp[i][j] = minHealth;
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size(); m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        
        return solve(dungeon,0,0,dp);
    }
};


// Tabulation - Bottom Up Approach 

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        
        dp[n-1][m-1] = max(-dungeon[n-1][m-1]+1,1);
        
        for(int i=n-2;i>=0;i--){
            dp[i][m-1] = max(dp[i+1][m-1]-dungeon[i][m-1],1);
        }
        for(int j=m-2;j>=0;j--){
            dp[n-1][j] = max(dp[n-1][j+1]-dungeon[n-1][j],1);
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j] , 1);
            }
        }
        return max(1,dp[0][0]);
    }
};
