class Solution {
public:
    // TC O(N^2)
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> mat(n,vector<int>(n,1));
        for(auto v:mines) mat[v[0]][v[1]] = 0;
        
        vector<vector<int>> left,right,top,bottom;
        left = right = top = bottom = mat;
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if(i-1>=0 and top[i][j]==1) top[i][j] += top[i-1][j];
                 if(j-1>=0 and left[i][j]==1) left[i][j] += left[i][j-1];
                 // int x = n-1-i;
                 // int y = n-1-j;
                 // if(y+1<n and right[x][y]==1) right[x][y] += right[x][y+1];
                 // if(x+1<n and bottom[x][y]==1) bottom[x][y] += bottom[x+1][y];
            }
         }
        //
         for(int i=n-1;i>=0;i--){
             for(int j=n-1;j>=0;j--){
                 if(j+1<n and right[i][j]==1) right[i][j] += right[i][j+1];
                 if(i+1<n and bottom[i][j]==1) bottom[i][j] += bottom[i+1][j];
             }
         }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,min({top[i][j],left[i][j],right[i][j],bottom[i][j]}));
            }
        }
        return ans;
    }
};









// TLE 
  // O(N^3) check for each i,j
    // int solve(int i,int j,vector<vector<int>> &board){
    //     int n = board.size();
    //     auto isSafe = [&](int i,int j)->bool{
    //         if(i<0 or j<0 or i>=n or j>=n or board[i][j]==0) return false;
    //         return true;
    //     };
    //     int k=0;
    //     for(k=0;k<=(n+1)/2;k++){
    //          if(isSafe(i+k*1,j) and isSafe(i,j+k*1) and isSafe(i-k*1,j) and isSafe(i,j-k*1)) continue;
    //         else break;
    //     }
    //     return k;
    // }
