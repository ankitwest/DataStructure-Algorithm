
// GFG
class Solution{
 public:
    //Function to find a solved Sudoku. 
    bool valid(int row,int col,int grid[N][N],int val){
        for(int i=0;i<9;i++){
            if(row==i) continue;
            if(grid[i][col]==val) return false;
        }
        for(int i=0;i<9;i++){
            if(col==i) continue;
            if(grid[row][i]==val) return false;
        }
        
        int start_row=row/3*3;
        int start_col=col/3*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(row==i+start_row and col==j+start_col) continue;
                 if(grid[i+start_row][j+start_col]==val) return false;
            }
        }
        return true;
        
    }
//         bool sudoku(int i,int j,int grid[N][N]){
//          for(int i=0;i<N;i++){
//             for(int j=0;j<N;j++){
//                 if(grid[i][j]==0){
//                     for(int choice=1;choice<=9;choice++){
//                         if(valid(i,j,grid,choice)){
//                             grid[i][j]=choice;
//                             if(sudoku(i,j,grid)) return true;
//                             grid[i][j]=0;
//                         }
//                     }//for loop
//                     return false;
//                 }
//             }
//         }
//         return true; 
//     }
    
    bool sudoku(int i,int j,int grid[N][N]){
        if(i==N) return true;
            
        int new_i=0,new_j=0;
        if(j==N-1) new_i=i+1,new_j=0;
        else new_i=i,new_j=j+1;
        
        //Already filled
        if(grid[i][j]!=0){
            return sudoku(new_i,new_j,grid);
        }
        else{  // Empty boxes
            for(int k=1;k<=9;k++){
                if(valid(i,j,grid,k)){
                  grid[i][j]=k;
                  if(sudoku(new_i,new_j,grid)) return true;
                  grid[i][j]=0;
                }
            }
            return false;
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        return sudoku(0,0,grid);
    }
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
//             cout<<endl;
        }
    }
};
Expected Time Complexity: O(9^(N*N)).


// LeetCode  copied

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c; 
                            
                            if(solve(board))
                                return true; 
                            else
                                board[i][j] = '.'; 
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) 
                return false; 
            
            if(board[row][i] == c) 
                return false; 
            
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
                return false; 
        }
        return true;
    }
};








// is Valid Soduko  gfg

class Solution{
public:
    bool valid(int row,int col,vector<vector<int>> &mat,int val){
        for(int i=0;i<9;i++){
            if(row==i) continue;
            if(mat[i][col]==val) return false;
        }
        for(int i=0;i<9;i++){
            if(col==i) continue;
            if(mat[row][i]==val) return false;
        }
        
        int start_row=row/3*3;
        int start_col=col/3*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(row==i+start_row and col==j+start_col) continue;
                 if(mat[i+start_row][j+start_col]==val) return false;
            }
        }
         return true;
        
    }
    int isValid(vector<vector<int>> mat){
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) continue;
                else{
                    int val = mat[i][j];
                    if(!valid(i,j,mat,val)) return false;
                }
            }
        }
        return true;
    }
};
Expected Time Complexity: O(N2)
