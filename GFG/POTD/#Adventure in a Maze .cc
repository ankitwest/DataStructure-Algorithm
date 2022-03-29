

class Solution {
public:
const int mod = 1000000007;
    vector<int> FindWays(vector<vector<int>>&matrix){
             int n = matrix.size();
             
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<vector<int>> best(n,vector<int>(n,0));
        
        dp[0][0] = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int up=0,left=0;
                int up_sum=0,left_sum=0;
                
                if(i>0 and dp[i-1][j]!=0 and (matrix[i-1][j]==2 or matrix[i-1][j]==3))
                up = dp[i-1][j] , up_sum = best[i-1][j];
                
                if(j>0 and dp[i][j-1]!=0 and (matrix[i][j-1]==1 or matrix[i][j-1]==3))
                left = dp[i][j-1] , left_sum = best[i][j-1];
                
                dp[i][j] = max(dp[i][j] , (up+left));   dp[i][j] %= mod;
                best[i][j] = matrix[i][j] + max(up_sum , left_sum); best[i][j] %= mod;
            }
        }
        
        int totalPath  = dp[n-1][n-1];
        int maxSum = totalPath == 0 ? 0 : best[n-1][n-1];
        return {totalPath, maxSum};
    }
};








not working
 //   auto solve = [&](auto solve,int i,int j){
    //         if(i<0 or j<0)
    //             return 0;
    //         if(i==0 and j==0)
    //             return 1;
                
    //         if(dp[i][j]!=-1)
    //             return dp[i][j];
            
    //         int ways = 0;
    //         if(matrix[i][j]==1)
    //             ways = solve(solve,i,j-1);
    //         else if(matrix[i][j]==2)
    //             ways = solve(solve,i-1,j);
    //         else if(matrix[i][j]==3)
    //             ways = (solve(solve,i-1,j) + solve(solve,i,j-1))%mod;
            
    //         return dp[i][j] = ways;
    //   };
    
    // auto helper = [&](auto helper,int i,int j){
    //         if(i<0 or j<0)
    //             return 0;
    //         if(i==0 and j==0)
    //             return matrix[i][j];
            
    //         if(best[i][j]!=-1)
    //             return best[i][j];
            
    //         int sum = 0;
    //         if(matrix[i][j]==1)
    //             sum = helper(helper,i,j-1);
    //         else if(matrix[i][j]==2)
    //             sum = helper(helper,i-1,j);
    //         else if(matrix[i][j]==3)
    //             sum = max(helper(helper,i-1,j) , helper(helper,i,j-1));
            
    //         sum += matrix[i][j]%mod;
    //         return best[i][j] = sum;
    //   };
    //   int x = solve(solve,n-1,n-1);
    //   int y = x == 0 ? 0 : helper(helper,n-1,n-1);
    
    
//   wroong answer  
    
    class Solution {
public:
const int mod = 1000000007;
    vector<int> FindWays(vector<vector<int>>&matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<int>> best(n,vector<int>(n,-1));
        
   
       
    auto solve2 = [&](auto solve2,int i,int j){
        if(i>=n or j>=n)
            return 0;
        if(i==n-1 and j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int ways = 0;
        if(matrix[i][j]==1)
            ways = solve2(solve2,i,j+1);
        else if(matrix[i][j]==2)
            ways = solve2(solve2,i+1,j);
        else if(matrix[i][j]==3)
            ways = (solve2(solve2,i+1,j) + solve2(solve2,i,j+1))%mod;
            
        return dp[i][j] = ways;
      };
        auto helper2 = [&](auto helper2,int i,int j){
            if(i>=n or j>=n)
                return 0;
            if(i==n-1 and j==n-1)
                return matrix[i][j];
            
            if(best[i][j]!=-1)
                return best[i][j];
            
            int sum = 0;
            
            if(matrix[i][j]==1)
                sum = helper2(helper2,i,j+1);
            else if(matrix[i][j]==2)
                sum = helper2(helper2,i+1,j);
            else if(matrix[i][j]==3)
                sum = max(helper2(helper2,i+1,j) , helper2(helper2,i,j+1));
            
            sum += matrix[i][j]%mod;
            return best[i][j] = sum;
      };
      int x = solve2(solve2,0,0);
      int y = x == 0 ? 0 : helper2(helper2,0,0);
       
       
       return {x,y};
    }
};
