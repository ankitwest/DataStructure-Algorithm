

class Solution {
public:
    int n,m; 
    int dp[101][101][201];
    int solve(int i,int j,int cnt,vector<vector<char>>& grid){
        if(i<0 or j<0 or i>=n or j>=m or cnt<0) return 0;
        
        grid[i][j]=='(' ? cnt++ : cnt--;
        
        if(cnt<0) return 0;
        
        if(i==n-1 and j==m-1) 
            return cnt==0;
        
        if(dp[i][j][cnt]!=-1)
            return dp[i][j][cnt];
        
        bool ans = solve(i+1,j,cnt,grid) | solve(i,j+1,cnt,grid);
        return dp[i][j][cnt] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size(); m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,grid);
    }
};
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.
