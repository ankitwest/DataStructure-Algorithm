class Solution {
    const int d[5] = {-1,0,1,0,-1}; 
    bool isValid(int a,int b,vector<vector<int>>& mat){
        return a>=0 and b>=0 and a<mat.size() and b<mat[0].size();
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (mat[i][j]==0) q.push({i,j});
                else mat[i][j] = -1;
            }
        }
        
        int dist = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto [x,y] = q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int a = x + d[k]; int b = y + d[k+1];
                    if(isValid(a,b,mat) and mat[a][b] == -1){
                        q.push({a,b});
                        mat[a][b] = dist;
                    }
                }   
            }
            dist++;
        }
        return mat;
    }
};



class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};
