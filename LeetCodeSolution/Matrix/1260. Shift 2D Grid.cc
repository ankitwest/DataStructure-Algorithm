


class Solution1 {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> mat(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int new_val = ((i*m + j) + k)%(n*m);
                int new_x = new_val/m;
                int new_y = new_val%m;
                mat[new_x][new_y] = grid[i][j];
            }
        }
        return mat;
    }
};


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> mat(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               int new_j = (j+k)%m;
               int new_i = (i+(j+k)/m)%n;
               mat[new_i][new_j] = grid[i][j];
            }
        }
        return mat;
    }
};


Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]
