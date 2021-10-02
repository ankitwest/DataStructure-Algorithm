class Solution {
 void getCoordinate(int n,int s, int &row, int &col){
        row = n-1-(s-1)/n;
        col = (s-1)%n;
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
            col = n-1-col;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> vis(n*n+1,0);
        
          vis[1]=1;
        queue<pair<int,int>> q;
        q.push({1,0});
        while(!q.empty()){
           // pair<int,int> p;
                 pair<int,int> p ; p= q.front();q.pop();
            int row,col,curr = p.first, dist = p.second;
            if(curr==n*n)
                return dist;
            for(int dice=1; curr+dice<=n*n and dice<=6;dice++){
                getCoordinate(n,(curr+dice),row,col);
                int sfinal = board[row][col]==-1? (curr+dice):board[row][col]; // check for snake or ladder
                  if(vis[sfinal]==false)
                  {
                    vis[sfinal] = true;
                    q.push({sfinal,dist+1});
                  }
            }
        }
        return -1;
    }
};
