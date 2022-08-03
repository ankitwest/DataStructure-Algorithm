class Solution{
public:
int dx[8] = {1, -1, 0, 0,1,1,-1,-1};
  int dy[8] = {0, 0, 1, -1,1,-1,1,-1};
    bool dfs(int x,int y,int index,int n,int m,vector<vector<char>> &board,string &word,vector<vector<bool>> &vis){
        if(x<0 or y<0 or x>=n or y>=m or vis[x][y] or board[x][y]!=word[index]) return false;
        
         if(index==word.size()-1) return true;
         if(index>=word.size()) return false;
        
        vis[x][y] = true;
        
        for(int k=0;k<8;k++){
           bool res = dfs(x+dx[k],y+dy[k],index+1,n,m,board,word,vis);
           if(res)
                return true;
        }
          
          
    // for(int i=-1;i<=1;i++){
    //     for(int j=-1;j<=1;j++){
    //         if(i == 0 && j == 0)continue;
    //         if(dfs(x+i,y+j,index+1,n,m,board,word,vis))return true;
    //     }
    // }
            
        vis[x][y] = false;
        return false;
        
    }
    bool isWordExist(vector<vector<char>> &board,string &word){
        int n = board.size(); int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
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


word-boggle 2
https://practice.geeksforgeeks.org/problems/72cf44eabd18006810efad06fbb623a0682acee2/1
