
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(); int m = matrix[0].size();
        int row = -1;
        for(int i=0;i<n;i++){
            if(target<=matrix[i][m-1])
                {row = i;break;}
        }
        if(row==-1) return false;
        
        int l=0,r=m;
        while(l<=r){
            int mid = (l+r)>>1;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
};

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

    
    
    
240. Search a 2D Matrix II

    
    
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
