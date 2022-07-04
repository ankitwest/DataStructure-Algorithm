class Solution1 {
    bool valid(vector<vector<char>>& board,char ch,int row,int col){
        for(int i=0;i<9;i++){
            if(i==row) continue;
            else if(board[i][col]==ch) return false;
        }
        for(int j=0;j<9;j++){
            if(j==col) continue;
            else if(board[row][j]==ch) return false;
        }
        
        int i1 = row/3*3;
        int j1 = col/3*3;
        for(int i=i1;i<i1+3;i++){
            for(int j=j1;j<j1+3;j++){
                if(i==row and j==col) continue;
                else if(board[i][j]==ch) return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(int k='1';k<='9';k++){
                        if(valid(board,k,i,j)){
                            board[i][j] = k;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

class Solution {
    bool valid(vector<vector<char>>& board,char ch,int row,int col){
        for(int i=0;i<9;i++){
            if(i==row) continue;
            else if(board[i][col]==ch) return false;
        }
        for(int j=0;j<9;j++){
            if(j==col) continue;
            else if(board[row][j]==ch) return false;
        }
        
        int i1 = row/3*3;
        int j1 = col/3*3;
        for(int i=i1;i<i1+3;i++){
            for(int j=j1;j<j1+3;j++){
                if(i==row and j==col) continue;
                else if(board[i][j]==ch) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int i,int j){
        if(i==9) return true;
        if(j==9) return solve(board,i+1,0);
        
        if(board[i][j] != '.') 
            return solve(board,i,j+1);
                    
        for(int k='1';k<='9';k++){
            if(valid(board,k,i,j)){
                board[i][j] = k;
                if(solve(board,i,j+1)) return true;
                board[i][j] = '.';
            }
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};

