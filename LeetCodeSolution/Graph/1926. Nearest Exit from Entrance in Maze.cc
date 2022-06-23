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


//sau
class Solution {
public:
    int dx[4] = {-1 , 1 , 0 , 0};
    int dy[4] = {0 , 0 , -1 , 1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size() , m = maze[0].size();
        int x = entrance[0] , y = entrance[1];
        
        vector<vector<int>> v(n , vector<int>(m , INT_MAX));
        
        v[x][y] = 0;
        set<pair<int,pair<int,int>>> s;
        
        s.insert({0 , {x , y}});
        
        while(s.size())
        {
            auto tp = *s.begin();
            s.erase(s.begin());
            auto dis = tp.first;
            int x1 = tp.second.first;
            int y1 = tp.second.second;
            
            for(int i=0;i<4;i++)
            {
                int a = x1 + dx[i];
                int b = y1 + dy[i];
                
                if(a < n && b < m && a >= 0 && b >= 0 && maze[a][b] != '+')
                {
                    if(v[a][b] > v[x1][y1] + 1)
                    {
                        v[a][b] = (v[x1][y1] + 1);
                        s.insert({v[a][b] , {a , b}});
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i == n - 1 || j == m - 1 || i == 0 || j == 0))
                {
                    if(i != x)
                        ans = min(ans , v[i][j]);
                    if(j != y)
                        ans = min(ans , v[i][j]);
                }
                     
            }
            // cout<<"\n";
        }
        // cout<<"\n";
        
        return ans == INT_MAX ? -1 : ans;
        
    }
};
