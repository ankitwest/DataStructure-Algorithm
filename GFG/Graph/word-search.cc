class Soluiton{
  public:
int dx[4] = {1, -1, 0, 0};
 int dy[4] = {0, 0, 1, -1};
    bool dfs(int x,int y,int n,int m,int index,string &word,vector<vector<char>>& board,vector<vector<int>> &vis){
        if (index == word.size()) return true;
        
        if(x<0 or y<0 or x>=n or y>=m or vis[x][y]==1) return false;
        if(board[x][y]!=word[index]) return false;
        
        vis[x][y]=1;
        
        for (int k = 0; k < 4; k++) 
          if(dfs(x+dx[k],y+dy[k],n,m,index+1,word,board,vis)) return true;
       
        vis[x][y]=0;
        return false;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size(); int m = board[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(board[i][j]==word[0])
                if(dfs(i,j,n,m,0,word,board,vis))
                    return true;
           }
       }
       return false;
    }
};
Expected Time Complexity: O(N * M * 4L) 
