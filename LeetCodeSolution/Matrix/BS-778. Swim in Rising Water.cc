class Solution {
public:
        int d[5] = {-1,0,1,0,-1}; 
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = max({2*(n-1),grid[0][0],grid[n-1][n-1]}); int high = n*n-1; // define correctly
        int ans = 0;
        // vector<vector<bool>> vis(maxN,vector<bool>(maxN,false));  not working vvb
        bool vis[50][50]={};
        
        auto solve = [&](const auto& solve,int i,int j,int mid) -> bool{
            if(i<0 or j<0 or i>=n or j>=n or vis[i][j] or grid[i][j]>mid) return false;
            if(i==n-1 and j==n-1) return true;
            vis[i][j]=true;
            
            for(int k=0;k<4;k++){
                if(solve(solve,i+d[k],j+d[k+1],mid)) return true;
            }
            return false;
        };
        while(low<=high){
            int mid = low + (high-low)/2;
            if(solve(solve,0,0,mid))
                ans = mid,high = mid-1;
            else 
                low = mid+1;
            // vis.resize(maxN,vector<bool>(maxN,false));
            memset(vis, false, sizeof(vis));      
        }
        return ans;
    }
};

Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
