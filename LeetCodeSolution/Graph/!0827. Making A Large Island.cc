

class Solution {
public:
    int findArea(vector<vector<int>>& grid,int i,int j,int id){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]!=1) return 0;        
        
        grid[i][j] = id;
        
        return 1 + findArea(grid,i+1,j,id) + findArea(grid,i-1,j,id) + 
            findArea(grid,i,j+1,id) + findArea(grid,i,j-1,id);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int id = 2; int n = grid.size(); int m = grid[0].size();
        map<int,int> mp; 
        mp[0] = 0; int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area = findArea(grid,i,j,id);
                    ans = max(ans,area);
                    mp[id++] = area;
                }
            }
        }
        
        int d[5] = {0,1,0,-1,0};
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    set<int> s;
                    for(int k=0;k<4;k++){
                        int new_x = i + d[k]; int new_y = j + d[k+1];
                        if(new_x<0 or new_y<0 or new_x>=n or new_y>=m) continue;
                        int id2 = grid[new_x][new_y];
                        s.insert(id2);
                    }
                    int sum = 1;
                    for(auto id :s) sum += mp[id];
                    ans = max(ans, sum);
                }
            }
         }
        return ans;
    }
};

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
