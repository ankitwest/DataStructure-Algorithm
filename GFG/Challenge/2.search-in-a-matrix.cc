class Solution{
  public:
    vector<bool> matSearch(vector<vector<int>>& mat, int n, int m, int q, vector<vector<int>>& vec){
        auto isValid = [&](int i,int j,int x1,int y1,int x2,int y2){
            if(i<x1 or j<y1 or i>x2 or j>y2) return false;
            return true;
        };
        vector<bool> ans(q,false);
      for(int i=0;i<q;i++){
          vector<int> v = vec[i];
          int x1 = v[0];int x2 = v[2]; int key = v[4];
          int y1 = v[1];int y2 = v[3];
          
        int curr_i = x1;int curr_j = y2;
          while(1){
              int curr_val = mat[curr_i][curr_j];
              if(curr_val==key) {
                  ans[i] = true; break;
              }
              else if(curr_val>key) curr_j--;
              else curr_i++;
              
              if(!isValid(curr_i,curr_j,x1,y1,x2,y2)) break;
          }
      }
      return ans;
  }
};Input: mat[][] = {{1,2,4,6},
                  {3,4,8,9},
                  {5,6,9,12}}
q = 2
x1 = 0, y1 = 0, x2 = 1, y2 = 2, key = 4
x1 = 0, y1 = 1, x2 = 2, Y2 = 3, key = 11
Output: 
True False
Explanation:
key = 4 is present in the the given sub-matrix
key  = 11 dosen't exixt in the given sub-matrix


