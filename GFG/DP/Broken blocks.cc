
class Solution{
public:  // not understood
    vector<vector<int>> dp; int n,m;
    int check(int i,int j,vector<vector<int>>&matrix)
    {
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]==-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int maxi = max({check(i+1,j,matrix),check(i+1,j-1,matrix),check(i+1,j+1,matrix)});
         maxi += matrix[i][j];
         return dp[i][j] = maxi;
    }
    int MaxGold(vector<vector<int>>&matrix)
    {
        n = matrix.size();  m = matrix[0].size();
        dp.resize(n,vector<int>(m,-1));
        
        int ans = INT_MIN;
        // for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,check(0,j,matrix));
            }
            // break;
        // }
        return ans;
    }
};

// bottom up
// we are taking the maximum from the ith row and storing it in i+1th row;
// when ith row is -1 then we give the result of i-1th row
class Solution{
public:
     int MaxGold(vector<vector<int>>&matrix)
    {
        int n = matrix.size();  int m = matrix[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            bool flag = false;
             for(int j=0;j<m;j++){
                 if(i==0){
                     flag = true;
                     ans = max(ans,matrix[i][j]);
                 }else{
                     if(matrix[i][j]==-1) continue;
                     int a = (i-1>=0) ? matrix[i-1][j] : -1;
                     int b = (i-1>=0 and j-1>=0) ? matrix[i-1][j-1] : -1;
                     int c = (i-1>=0 and j+1< m) ? matrix[i-1][j+1] : -1;
                     if(a==-1 and b==-1 and c==-1) continue;
                     matrix[i][j] += max({a,b,c});
                     flag = true;
                     ans = max(ans,matrix[i][j]);
                 }
             }
             if(!flag) return ans;
        }
        return ans;
    }
    };
