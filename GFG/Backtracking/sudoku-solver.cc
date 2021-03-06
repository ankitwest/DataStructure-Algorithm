
// GFG
class Solution{
 public:
    //Function to find a solved Sudoku. 
    bool valid(int row,int col,int grid[N][N],int val){
        for(int i=0;i<9;i++){
//             if(row==i) continue;
            if(grid[i][col]==val) return false;
        }
        for(int i=0;i<9;i++){
//             if(col==i) continue;
            if(grid[row][i]==val) return false;
        }
        
        int i1 = row/3*3;
        int j1 = col/3*3;
        for(int i=i1;i<i1+3;i++){
            for(int j=j1;j<j1+3;j++){
//                 if(i==row and j==col) continue; 
                if(grid[i][j]==val) return false;
            }
        }
        return true;
        
    }
       bool sudoku(int grid[N][N]){
         for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    for(int choice=1;choice<=9;choice++){
                        if(valid(i,j,grid,choice)){
                            grid[i][j]=choice;
                            if(sudoku(grid)) return true;
                            grid[i][j]=0;
                        }
                    }//choice for loop
                    return false;
                }
            }
        }
        return true;
    }
    
//     bool sudoku(int i,int j,int grid[N][N]){
//         if(i==N) return true;
            
//         int new_i=0,new_j=0;
//         if(j==N-1) new_i=i+1,new_j=0;
//         else new_i=i,new_j=j+1;
        
//         //Already filled
//         if(grid[i][j]!=0){
//             return sudoku(new_i,new_j,grid);
//         }
//         else{  // Empty boxes
//             for(int k=1;k<=9;k++){
//                 if(valid(i,j,grid,k)){
//                   grid[i][j]=k;
//                   if(sudoku(new_i,new_j,grid)) return true;
//                   grid[i][j]=0;
//                 }
//             }
//             return false;
//         }
//         return true;
//     }
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
