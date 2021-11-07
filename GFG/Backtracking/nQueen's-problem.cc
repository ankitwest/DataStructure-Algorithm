class Solution{
public:
    bool isSafe(vector<vector<int>> &arr,int row,int col,vector<int> &v,int n){
        int row1=row; 
        int col1=col;
        while(col>=0){
            if(arr[row][col]==1) return false;
            col--;
        }
        row=row1;
        col=col1;
        while(row>=0 and col>=0){
            if(arr[row][col]==1) return false;
            row--;
            col--;
        }
        
        row=row1;
        col=col1;
        while(row<n and col>=0){
             if(arr[row][col]==1) return false;
            row++;
            col--;
        }
        return true;
        
    }
    void nQueenUtil(vector<vector<int>> &arr,int col,vector<int> &v,vector<vector<int>> &ans,int n){
        if(col==n){
            ans.push_back(v);
            return ;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(arr,row,col,v,n)){
                arr[row][col]=1;
                v.push_back(row+1);
                nQueenUtil(arr,col+1,v,ans,n);
                arr[row][col]=0;
                v.pop_back();
            }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<int> v;
        vector<vector<int>> ans;
        vector<vector<int>> arr(n,vector<int>(n,0));
        nQueenUtil(arr,0,v,ans,n);
        return ans;
    }
};

Expected Time Complexity: O(n!)
  or
  Expected Time Complexity: O(2^n)

      
      
      
      // LeetCode
      class Solution {
public:
    bool isSafe1(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--; 
        }
        
        return true; 
    }
public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe1(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        solve(0,board, ans, n); 
        return ans; 
    }
    
};

Efficient
class Solution {

public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &leftRow, 
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        
        for(int row = 0;row<n;row++) {
            if(leftRow[row]==0 && lowerDiagonal[row + col] == 0 
               && upperDiagonal[n-1 + col - row] == 0) {
                
                board[row][col] = 'Q'; 
                leftRow[row] = 1; 
                lowerDiagonal[row+col] = 1; 
                upperDiagonal[n-1 + col - row] = 1;
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
                board[row][col] = '.'; 
                leftRow[row] = 0; 
                lowerDiagonal[row+col] = 0; 
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
        solve(0,board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
        return ans; 
    }
    
};
