class Solution {
    int n,m;
    const int d[5] = {0,1,0,-1,0};
    void dfs(vector<vector<int>>& matrix,vector<vector<bool>> &vis,int i,int j,int pre){
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j] or pre>matrix[i][j]) return;
        
        vis[i][j] = true;
        
        for(int k=0;k<4;k++){
             dfs(matrix,vis,i+d[k],j+d[k+1],matrix[i][j]);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> v;
        n = matrix.size(); m = matrix[0].size();
        if(n==0 or m==0) return v;
        
        vector<vector<bool>> pacific(n, vector<bool>(m,false));
        vector<vector<bool>> atlantic(n, vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            dfs(matrix,pacific,i,0,-1);  // 0,0 to n-1,0
            dfs(matrix,atlantic,i,m-1,-1); //0,m-1 to n-1,m-1
        }
        
        for(int j=0;j<m;j++){
            dfs(matrix,pacific,0,j,-1);  //0,0 to 0,m-1
            dfs(matrix,atlantic,n-1,j,-1); //n-1,0 to n-1,m-1
        }
        
         for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (pacific[i][j] && atlantic[i][j])
                    v.push_back({i,j});
            }
        }
        return v;
    }
};
