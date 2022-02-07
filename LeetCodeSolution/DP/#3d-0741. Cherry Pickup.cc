class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> memo;
    int f(int r1,int c1,int r2,vector<vector<int>>& grid){
        int c2 = r1+c1-r2;

        //base case
        if(r1==n-1 and c1==m-1)
            return grid[r1][c1];
        
        if(r1<0 or r1>=n or r2<0 or r2>=n or c1<0 or c1>=m or c2<0 or c2>=m or grid[r1][c1]==-1 or grid[r2][c2]==-1 ) return INT_MIN;
        
        //mem check
        if(memo[r1][c1][r2]!=-1)
            return memo[r1][c1][r2];
        
        //calculating ans
        int ans = 0;
        if(r1==r2 and c1==c2) ans = grid[r1][c1];
        else ans = grid[r1][c1] + grid[r2][c2];
        
        // 4 passible path
        int p1 = f(r1+1,c1,r2+1,grid);
        int p2 = f(r1,c1+1,r2,grid);
        int p3 = f(r1+1,c1,r2,grid);
        int p4 = f(r1,c1+1,r2+1,grid);
        ans += max({p1,p2,p3,p4});
        
        return memo[r1][c1][r2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memo.resize(n,vector<vector<int>>(m,vector<int>(n,-1)));
        
        // f(0,0,0,grid);
        return max(0,f(0,0,0,grid));
    }
};
