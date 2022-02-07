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


Not working
class Solution {
public:
int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(m,vector<int>(m,0)));
        
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                memo[n-1][j1][j2] = (j1==j2)?grid[n-1][j1]:grid[n-1][j1]+grid[n-1][j2];
            }
        }
        
        for(int i=n-2;i>=0;i++){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi = -1e5;
                    
                    // inner loop to pick the best of all 9 posible options
                    for(int x=-1;x<=1;x++){
                        for(int y=-1;y<=1;y++){
                            int ans=0;
                            ans = (j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
                            
                            // if(j1==j2) ans = grid[i][j1];
                            // else ans = grid[i][j1]+grid[i][j2];
                                
                            
                            if(j1+x>=0 and j1+x<m and j2+y>=0 and j2+y<m)
                                ans += memo[i+1][j1+x][j2+y];
                            else 
                                ans += -1e9;
                            maxi = max(maxi,ans);
                        }
                    }
                    
                    memo[i][j1][j2] = maxi;
                }
            }
        }
        
        return memo[0][0][m-1];
        
    }
};
