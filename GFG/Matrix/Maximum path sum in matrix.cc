class Solution{
private:
    vector<vector<int>> dp;
   int solve(int i,int j, vector<vector<int>> &mat,int n){
       if(i==n) 
            return 0;
            
        if(j<0 or j>=n)
            return INT_MIN;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int ans = 0;
        ans = mat[i][j] + max({solve(i+1,j,mat,n), solve(i+1,j-1,mat,n), solve(i+1,j+1,mat,n)});
        
        return dp[i][j] = ans;
   }
public:
   int maximumPath(int N, vector<vector<int>> mat)
   {
       int n = mat.size();
       dp.resize(n,vector<int>(n,-1));
       int maxi = INT_MIN;
       for(int j=0;j<n;j++){
           maxi = max(maxi,solve(0,j,mat,n));
       }
       return maxi;
   }
};


class Solution2{
public:
     /////// tabulation
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        int m = n;
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0)
                    dp[i][j] = matrix[i][j] + max({dp[i-1][j] , dp[i-1][j+1]});
                else if(j==m-1)
                    dp[i][j] = matrix[i][j] + max({dp[i-1][j] , dp[i-1][j-1]});
                else
                    dp[i][j] = matrix[i][j] + max({dp[i-1][j] , dp[i-1][j-1] , dp[i-1][j+1]});
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.
