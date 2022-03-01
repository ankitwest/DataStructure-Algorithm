class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(); int m = heights[0].size();
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        
        queue<pair<int,int>> q;
        q.push({0,0,});
        int d[5] = {-1,0,1,0,-1};
        effort[0][0] = 0;
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int x = curr.first; int y = curr.second;
            
            for(int k=0;k<4;k++){
                int new_x = x + d[k]; int new_y = y + d[k+1];
                
                if(new_x<0 or new_y<0 or new_x>=n or new_y>=m) continue;
                if(effort[new_x][new_y]<=effort[x][y]) continue;
                
                int p = max(effort[x][y],abs(heights[new_x][new_y]-heights[x][y]));
                effort[new_x][new_y] = min(effort[new_x][new_y],p);
                q.push({new_x,new_y});
             }
        }
        return effort[n-1][m-1];
    }
};

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
