


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







live



working nw??





// yes sir //join the call

/// sir /// are you there ???  





Hi , are still online  ?

// yes sir 


Cool, Let's jump on call
// meet call  you mean? https://meet.google.com/nos-jhyh-gqq 




#include <bits/stdc++.h>
using namespace std;

// Recursion approach 1 with memoizatinn


int mini = INT_MAX;;
vector<pair<int,int>> path;

vector<vector<int>> grid;   //  grid  vector of vector for method 1
vector<vector<int>> memo;  // memo  vector of vector
int recur(int i,int j,int n,int m,vector<pair<int,int>> &curr_path,int &sigma,vector<vector<bool>> &vis)
{
  if(i>=n or j>=m) return INT_MAX;  // boundary case where we return max value as we will get the other cell answer when we will take minimum;
  if(i==n-1 and j==m-1) return max(0,-grid[n-1][m-1]); // base case  of exit cell where we reuired sth or not ; 

  if(memo[i][j]!=-1) return memo[i][j];  // if already found that recursive call thne we can return the stored value rather than computing agian;

  int curr_min = min(recur(i+1,j,n,m,curr_path,sigma,vis),recur(i,j+1,n,m,curr_path,sigma,vis))   // calculating the current cell required value 

  int curr = curr_min - grid[i][j];
  curr = max(0,curr);  // taking max with 0 if the required value is negative 
  sigma += curr;

curr_path.push_back({i,j}),vis[i][j] = true; 

  if(i==0 and j==0){
    if(sigma<mini){
      mini = sigma; path = curr_path;
      curr_path.clear();
  }

  vis[i][j] = false; 

  return memo[i][j] = curr;   // memoization and returning the value for recursinn
}





int main()
 {
  int n,m;cin>>n>>m;     // taking input value of row and column;
  grid.resize(n,vector<int>(m,0));  // resizing the grid vector of vector
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }

  vector<pair<int,int>> curr_path;
  vector<vector<bool>> vis;
  int sigma=0;
 memo.resize(n,vector<int>(m,-1));  // resizing the memo vector of vector
int ans = recur(0,0,n,m,curr_path,sigma,vis);  // getting the answer

if(ans==0 and grid[0][0]==0) ans = 1;  // edge case where required budget is 0 and grid entry cell is 0 then and =1 ;
else if(ans==0 and grid[0][0]>0) ans = 0; // edge case where required budget is 0 and grid entry cell is positive then and =0 ; as we dont need anything more budget;
else ans = ans + 1;  //general case where  1 extra value is required;

  cout<<ans<<"\n";


// 00 01 02 12

  for(int i=0;i<v.size();i++){
    auto p = path[i];
    cout<<p.first<<" "<<p.second<<endl;
  }
  return 0;
}

-----+-----+------|
| 23 = 45  =  67  |
+----+-----+--# --+
| 23 | 45  |  67  |
+----+-----+-- #--+
| 23 | 45  |  67  |
+----+-----+--#---+
| 23 | 45  |  67  |
+----+-----+------+





















// #include <bits/stdc++.h>
// using namespace std;

// // Recursion approach 1 with memoizatinn


// stack<pair<int,int>> st;
// vector<vector<int>> grid;   //  grid  vector of vector for method 1
// vector<vector<int>> memo;  // memo  vector of vector
// int recur(int i,int j,int n,int m){
//   if(i>=n or j>=m) return INT_MAX;  // boundary case where we return max value as we will get the other cell answer when we will take minimum;
//   if(i==n-1 and j==m-1) return max(0,-grid[n-1][m-1]); // base case  of exit cell where we reuired sth or not ; 

//   if(memo[i][j]!=-1) return memo[i][j];  // if already found that recursive call thne we can return the stored value rather than computing agian;

//   int curr = min(recur(i+1,j,n,m),recur(i,j+1,n,m)) - grid[i][j];  // calculating the current cell required value 
//   curr = max(0,curr);  // taking max with 0 if the required value is negative 
//   return memo[i][j] = curr;   // memoization and returning the value for recursinn
// }


// int main() {
//   int n,m;cin>>n>>m;     // taking input value of row and column;
//   grid.resize(n,vector<int>(m,0));  // resizing the grid vector of vector
//   for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//       cin>>grid[i][j];
//     }
//   }
//  memo.resize(n,vector<int>(m,-1));  // resizing the memo vector of vector
// int ans = recur(0,0,n,m);  // getting the answer

// if(ans==0 and grid[0][0]==0) ans = 1;  // edge case where required budget is 0 and grid entry cell is 0 then and =1 ;
// else if(ans==0 and grid[0][0]>0) ans = 0; // edge case where required budget is 0 and grid entry cell is positive then and =0 ; as we dont need anything more budget;
// else ans = ans + 1;  //general case where  1 extra value is required;

//   cout<<ans<<"\n";
//   return 0;
// }


// //  // Tabulation approach 2 


// vector<vector<int>> grid;
// int main() 
// {
//   int n,m;cin>>n>>m;  // n = row  m = column
//   grid.resize(n,vector<int>(m,0)); // resizing the grid vector of vector
//   for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//       cin>>grid[i][j];
//     }
//   }
 
//   vector<vector<int>> dp;
//   dp.resize(n,vector<int>(m,0));  // a dp vector of vector to store the required amount to stay alive
//   dp[n-1][m-1] = max(0,-grid[n-1][m-1]);  // if value is positive then required budget is 0; // base case

//   for(int i=n-2;i>=0;i--){
//     dp[i][m-1] = dp[i+1][m-1] - grid[i][m-1];  // similarly we can look for the required value wrt next cell and curr value
//     dp[i][m-1] = max(0,dp[i][m-1]);   // if the required value (dp[i][m-1]) is positive then we can move to next cell otherwise if it negative it means we can survive without any pre budget and therfore 0;
//   }
//    for(int j=m-2;j>=0;j--){
//     dp[n-1][j] = dp[n-1][j+1] - grid[n-1][j];
//     dp[n-1][j] = max(0,dp[n-1][j]);
//   }

//   for(int i=n-2;i>=0;i--){
//     for(int j=m-2;j>=0;j--){
//       dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - grid[i][j];  // we will apply same approach but shall take minimum of right and down cell and shall subtract the curr value in it;
//       dp[i][j] = max(0,dp[i][j]);   // if it (dp[i][j]) is positive then we certiainly need that much amount of budget otherwise we can continue with 0 also;
//     }
//   }
// int ans = 0;
// if(dp[0][0]==0 and grid[0][0]==0) ans = 1;   // if the required value is zero and also grid entry value is zero then we need atleast one budget to survive and  reach till the exit cell
// else if(dp[0][0]==0 and grid[0][0]>0) ans = 0;  //if the required value is zero and grid entry vlaue is positive then it means we dont need any extra amount of budget, as we will always get rewarded in our commute towards end cell
// else ans=dp[0][0]+1;  // general case where we need 1 more then tne required budget;

//   // for(int i=0;i<n;i++){
//   //   for(int j=0;j<m;j++){
//   //     cout<<dp[i][j]<<" ";
//   //   }
//   //   cout<<"\n";
//   //   }





// for(int i=1;i<n;i++){
//     for(int j=1;j<m;j++){
//        int mini = min(dp[i-1][j],dp[i][j-1];
//        if(mini==dp[i-1][j]) v.push_back({i-1,j}); else v.push_back({i,j-1});
//        auto p = v.back();
//        if(p.first==i and p.second==j)
//     }
// }

// 00 01 02 12


//     // for(int i=n-2;i>=0;i--){
//     // for(int j=m-2;j>=0;j--){
//     //  int mini = max(dp[i+1][j],dp[i][j+1];

//     // }
//     // cout<<"\n";
//     // }


// 6 4 1
// 5 10 4
// 0 0 5


// 6 4 1
// 5 10 4
// 0 0 5

// (0,0) => () () 
//   cout<<ans<<"\n";
//   return 0;
// // }








