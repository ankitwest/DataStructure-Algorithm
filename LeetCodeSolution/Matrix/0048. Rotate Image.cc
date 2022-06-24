class Solution0 {
public:
    void rotate(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};

class Solution1 {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        // complement of matrix 
        for (int i = 0; i < n; ++i) {  
            for (int j = i; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);  
            }
        }
        // swap columns
         for (int i = 0; i < n; ++i) {
             int left = 0,right = n-1;
             while(left<right){
                 swap(matrix[i][left],matrix[i][right]);
                 left++,right--;
             }
         }
    }
};


class Solution {
public:
    void rotate(vector<vector<int> > &mat) {
        int n = mat.size(); 
        for(int i=0;i<n;i++){
            for(int j=i;j<n-1-i;j++){
                int temp = mat[i][j];                         //0,1 
                mat[i][j] = mat[n-1-j][i];                    //2,0 
                mat[n-1-j][i] = mat[n-1-i][n-1-j];            //3,2 
                mat[n-1-i][n-1-j] = mat[j][n-1-i];            //1,3 
                mat[j][n-1-i] = temp;
            }
        }
    }
};




// M-2 single N^2
class Solution3 {
public:
    void rotate(vector<vector<int> > &mat) {
        int n = mat.size(); int temp = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n - 1 - i; ++j){
                int *a1 = &mat[i][j];
                int *a2 = &mat[j][n - 1 - i];
                int *a3 = &mat[n - 1 - i][n - 1 - j];
                int *a4 = &mat[n - 1 - j][i];
                
                temp = *a1;
                *a1 = *a4;
                *a4 = *a3;
                *a3 = *a2;
                *a2 = temp;
            }
        }
    }
};
