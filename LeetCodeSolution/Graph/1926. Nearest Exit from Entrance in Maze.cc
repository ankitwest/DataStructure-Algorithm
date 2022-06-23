BFS

class Solution {
    const int d[5] = {-1,0,1,0,-1}; 
    bool isValid(int a,int b,vector<vector<char>>& maze){
        return a>=0 and b>=0 and a<maze.size() and b<maze[0].size();
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int sx = e[0]; int sy = e[1];
        int n = maze.size(); int m = maze[0].size();
        
        queue<pair<int,int>> q;
        q.push({sx,sy});
        maze[sx][sy] = '+'; int cnt = 1;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto [x,y] = q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int a = x + d[k]; int b = y + d[k+1];
                    if(isValid(a,b,maze) and maze[a][b]=='.'){
                        if(a==0 or a==n-1 or b==0 or b==m-1) return cnt;
                        q.push({a,b});
                        maze[a][b] = '+';
                    }
                }   
            }
            cnt++;
        }
        return -1;
    }
};
