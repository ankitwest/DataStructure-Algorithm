class Solution1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); int m = matrix[0].size();
        unordered_map<int,int> row,col; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) row[i] = 1,col[j] = 1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row.count(i) or col.count(j)) matrix[i][j] = 0;
            }
        }
    }
};


// TC - O(2*N*M)
 // col0 means zeroth_column
class Solution {
public: 
    void setZeroes(vector<vector<int> > &matrix) {
       int n = matrix.size(); int m = matrix[0].size();
        int col0 = 1;
         for(int i=0;i<n;i++){
            if(matrix[i][0] == 0) col0 = 0;
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(matrix[i][0] == 0 or matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(col0 == 0)
                matrix[i][0] = 0;
        }
    }
};

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]
