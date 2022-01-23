class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int zz) {
        int n = grid.size(); int m = grid[0].size();
 
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[start[0]][start[1]]=1;
        
        vector<array<int,4>> v;
        
        if(grid[start[0]][start[1]]>=pricing[0] and grid[start[0]][start[1]]<=pricing[1]){
                v.push_back({0,grid[start[0]][start[1]],start[0],start[1]});
        }
        
        int dist=1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto p = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int new_x = p.first+dx[k]; int new_y = p.second+dy[k];
                    if(new_x<0 or new_y<0 or new_x>=n or new_y>=m or grid[new_x][new_y]==0 or vis[new_x][new_y]==1)continue;
                        q.push({new_x,new_y});
                        vis[new_x][new_y]=1;
                    if(grid[new_x][new_y]>=pricing[0] and grid[new_x][new_y]<=pricing[1]){
                        v.push_back({dist,grid[new_x][new_y],new_x,new_y});
                    }
                }
            }
            dist++;
        }
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
            
        
        int i=0;
        for(int i=0;i<v.size() and zz>0;i++){
            vector<int> z;  
            z.push_back(v[i][2]); z.push_back(v[i][3]);
            ans.push_back(z);
            zz--;
        }
        return ans;
    }
};



https://leetcode.com/contest/biweekly-contest-70/problems/k-highest-ranked-items-within-a-price-range/
