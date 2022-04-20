


#include <bits/stdc++.h>
using namespace std;


// Recursion approach 1
vector<vector<int>> grid;
vector<vector<int>> memo;
int recur(int i,int j,int n,int m){
  if( i>=n or j>=m) return INT_MAX;
  if(i==n-1 and j==m-1) return max(0,-grid[n-1][m-1]);

  if(memo[i][j]!=-1) return memo[i][j];

  int curr =  min(recur(i+1,j,n,m),recur(i,j+1,n,m) ) - grid[i][j];
  curr = max(0,curr);
  return memo[i][j] = curr;
}
int main() {
  int n,m;cin>>n>>m;
  grid.resize(n,vector<int>(m,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }
 memo.resize(n,vector<int>(m,-1));
int ans = recur(0,0,n,m);
if(ans==0 and grid[0][0]==0) ans = 1;
else if(ans==0 and grid[0][0]>0) ans = 0;
else ans = ans + 1;
  cout<<(ans)<<endl;
  return 0;
}








 // tabulation approach 2
vector<vector<int>> grid;
int main() {
  int n,m;cin>>n>>m;
  grid.resize(n,vector<int>(m,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }
    
    vector<vector<int>> dp;
  dp.resize(n,vector<int>(m,0));  // a dp vector of vector to store the required amount to stay alive
  dp[n-1][m-1] = max(0,-grid[n-1][m-1]);  // if value is positive then required budget is 0;

  for(int i=n-2;i>=0;i--){
    dp[i][m-1] = dp[i+1][m-1] - grid[i][m-1];  // similar 
    dp[i][m-1] = max(0,dp[i][m-1]);
  }
   for(int j=m-2;j>=0;j--){
    dp[n-1][j] = dp[n-1][j+1] - grid[n-1][j];
    dp[n-1][j] = max(0,dp[n-1][j]);
  }

  for(int i=n-2;i>=0;i--){
    for(int j=m-2;j>=0;j--){
      dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - grid[i][j];
      dp[i][j] = max(0,dp[i][j]);
    }
  }
int ans = 0;
if(dp[0][0]==0 and grid[0][0]==0) ans = 1;
else if(dp[0][0]==0 and grid[0][0]>0) ans = 0; 
else ans=dp[0][0]+1;
  cout<<ans<<endl;

  return 0;
}
