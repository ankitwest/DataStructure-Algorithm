class Solution {
public:
    int n,m;
    int dx[8] = {1, -1, 0, 0,1,1,-1,-1};int dy[8] = {0, 0, 1, -1,1,-1,1,-1};
    bool dfs(int ind,int i,int j,string word,vector<vector<char>>& board){
        if(ind==word.size()) return true;
        if(i<0 or j<0 or i==n or j==m or board[i][j]=='#' or board[i][j]!=word[ind]) return false;
        
        board[i][j] = '#';
        
        for(int k=0;k<4;k++)
            if(dfs(ind+1,i+dx[k],j+dy[k],word,board)) return true;
        
        board[i][j] = word[ind];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(); m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0])
                    if(dfs(0,i,j,word,board)) return true;
            }
        }
        return false;
    }
};

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
