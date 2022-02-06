class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<int> row(n,0),col(n,0);
      vector<long long int> v;
      long long int ans = n*1LL*n;
      
      int r=n; int c=n;
      for(int i=0;i<k;i++){
          int x = arr[i][0]; x--;
          int y = arr[i][1]; y--;
          if(!row[x] and !col[y]){
              ans = ans-r-c+1;
              r--; c--;
          }else if(row[x] and !col[y]){
              ans = ans-r;
              c--;
          }else if(!row[x] and col[y]){
              ans = ans-c;
              r--;
          }
          v.push_back(ans);
          row[x]=1;col[y]=1;
      }
      return v;
  }
};

Input:
n = 3, k= 3
2 2
2 3
3 2
Output: 4 2 1
Explanation: 
After 1st Operation, all the 2nd row
and all the 2nd column will be filled by
1. So remaning cell with value 0 will be 4
After 2nd Operation, all the 2nd row and all
the 3rd column will be filled by 1. So 
remaning cell with value 0 will be 2.
After 3rd Operation cells having value 0 will
be 1.
