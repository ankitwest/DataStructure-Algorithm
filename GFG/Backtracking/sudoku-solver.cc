





// is Valid Soduko

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
