class Solution {
public:
    // TC - O(N*M*M*9)
    // SC - o(N*M*M) + O(N) for Auxillary Stack Recusrion
    int n;int m;
    vector<vector<vector<int>>> memo;
    
    int f(int i,int j1,int j2,vector<vector<int>>& grid){
        //base cases
        if(i==n) return -1e9;
        if(j1<0 or j1>=m or j2<0 or j2>=m) return -1e9;
        if(i==n-1){
            return (j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
        }
        // mem check
        if(memo[i][j1][j2]!=-1) 
            return memo[i][j1][j2];
        
        //check for all possible path of both robots
        int ans=0; int maxi = -1e9;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                ans = (j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
                ans += f(i+1,j1+x,j2+y,grid);
                
                maxi = max(maxi,ans);
            }
        }
        return memo[i][j1][j2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memo.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        f(0,0,m-1,grid);
        return memo[0][0][m-1];
    }
};
