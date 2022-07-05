class Solution {
public:  //better
    //DP to store; and dfs to make calls to neighbours
    int d[5] = {0,-1,0,1,0};
    vector<vector<int>> dp; int n,m;
    int dfs(vector<vector<int>> &mat,int i,int j,int pre){
        if(i<0 or j<0 or i>=n or j>=m or mat[i][j]<=pre) return 0;
        
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        int tot = 0;
        for(int k=0;k<4;k++){
            int t = dfs(mat,i+d[k],j+d[k+1],mat[i][j]);
            tot = max(tot, t);
        }
        return dp[i][j] = tot + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size(); m = mat[0].size();
        dp.resize(n,vector<int>(m,-1));
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(mat,i,j,-1));
            }
        }
        
        return ans;
    }
};






//similar 
//     int dfs(vector<vector<int>> &mat,int i,int j,int pre){   //also crt
//         if(i<0 or j<0 or i>=n or j>=m or mat[i][j]<=pre) return 0;
        
//         if(dp[i][j]!=-1) 
//             return dp[i][j];
        
//         int l = dfs(mat,i,j-1,mat[i][j]);
//         int r = dfs(mat,i,j+1,mat[i][j]);
//         int u = dfs(mat,i-1,j,mat[i][j]);
//         int d = dfs(mat,i+1,j,mat[i][j]);
              
//         int tot = max({l,r,u,d}) + 1;
//         return dp[i][j] = tot;
//     }

class Solution2 {
public:
    int d[5] = {0,-1,0,1,0};
    vector<vector<int>> dp; int n,m;
    int dfs(int i,int j,vector<vector<int>> &mat){
        if(i<0 or j<0 or i>=n or j>=m) return 0;
        
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        int ans = 0;
        for(int k=0;k<4;k++){
            int a = i+d[k]; int b = j+d[k+1];
            if(a>=0 && b>=0 && a<n && b<m){
                if(mat[a][b] > mat[i][j]){
                    ans = max(ans, 1 + dfs(a,b,mat));
                }
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size(); m = mat[0].size();
        dp.resize(n,vector<int>(m,-1));
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, dfs(i,j,mat));
            }
        }
        
        return ans+1;
    }
};


