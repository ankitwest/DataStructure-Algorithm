class Solution{
public:
    bool isSafe(vector<vector<int>> &arr,int row,int col,vector<int> &v,int n){
        int row1=row; 
        int col1=col;
        while(col>=0){
            if(arr[row][col]==1) return false;
            col--;
        }
        row=row1;
        col=col1;
        while(row>=0 and col>=0){
            if(arr[row][col]==1) return false;
            row--;
            col--;
        }
        
        row=row1;
        col=col1;
        while(row<n and col>=0){
             if(arr[row][col]==1) return false;
            row++;
            col--;
        }
        return true;
        
    }
    void nQueenUtil(vector<vector<int>> &arr,int col,vector<int> &v,vector<vector<int>> &ans,int n){
        if(col==n){
            ans.push_back(v);
            return ;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(arr,row,col,v,n)){
                arr[row][col]=1;
                v.push_back(row+1);
                nQueenUtil(arr,col+1,v,ans,n);
                arr[row][col]=0;
                v.pop_back();
            }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<int> v;
        vector<vector<int>> ans;
        vector<vector<int>> arr(n,vector<int>(n,0));
        nQueenUtil(arr,0,v,ans,n);
        return ans;
    }
};

Expected Time Complexity: O(n!)
  or
  Expected Time Complexity: O(2^n)
