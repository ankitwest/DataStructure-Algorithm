
class Solution {
public:
    int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
    int n;int m;
    bool isValid(int i,int j){
        if(i<0 or j<0 or i>=n or j>=m) return false;
        return true;
    }
    void reveal(vector<vector<char>>& board,int i,int j){
         if(board[i][j] == 'M'){
            // board[i][j] = 'X';
            return ;
        }
        
        if(board[i][j] == 'E'){
            int cnt = 0;
        
            for(int k=0;k<8;k++){
                if(isValid(i+dx[k],j+dy[k]) and board[i+dx[k]][j+dy[k]]=='M') cnt++;
            }

            if(cnt>0){
                board[i][j] = '0' + cnt;
                return;
            }else{
                board[i][j] = 'B';
                for(int k=0;k<8;k++){
                    if(isValid(i+dx[k],j+dy[k])) reveal(board,i+dx[k],j+dy[k]);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size(); m = board[0].size();
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        reveal(board,click[0],click[1]);
        return board;
    }
};
