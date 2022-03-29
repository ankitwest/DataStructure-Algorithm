

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); int m = matrix[0].size();
        int i = 0; int j=m-1;
        while(i<n and j>=0){
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]<target) i++;
            else j--;
        }
        return false;
    }
};

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
