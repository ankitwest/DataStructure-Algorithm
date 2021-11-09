
// Word Boggle


class Solution{
  public:
int dx[8] = {1, -1, 0, 0,1,1,-1,-1};
 int dy[8] = {0, 0, 1, -1,1,-1,1,-1};
    bool dfs(int x,int y,int index,int n,int m,vector<vector<char>> &board,string &word,vector<vector<int>> &vis){
        if(index==word.size()) return true;
        
        if(x<0 or y<0 or x>=n or y>=m or vis[x][y]==1) return false;
        if(board[x][y]!=word[index]) return false;
        
        vis[x][y]=1;
        
        for(int k=0;k<8;k++)
          if(dfs(x+dx[k],y+dy[k],index+1,n,m,board,word,vis)) return true;
          
          
    // for(int i=-1;i<=1;i++){
    //     for(int j=-1;j<=1;j++){
    //         if(i == 0 && j == 0)continue;
    //         if(dfs(x+i,y+j,index+1,n,m,board,word,vis))return true;
    //     }
    //  }
            
        vis[x][y]=0;
            return false;
        
    }
    bool isWordExist(vector<vector<char>> &board,string &word){
        int n = board.size(); int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,n,m,board,word,vis))
                    return true;
                }
            }
        }
        return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    vector<string> ans;
	    for(int i=0;i<dictionary.size();i++){
	        if(isWordExist(board,dictionary[i]))
	            ans.push_back(dictionary[i]);
	    }
	    return ans;
	}
};
Expected Time Complexity: O(N*W + R*C^2)








// Word Search



class Solution{
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
Expected Time Complexity: O(N * M * 4L
