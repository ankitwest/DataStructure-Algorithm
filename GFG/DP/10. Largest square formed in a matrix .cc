class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> s(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
            s[i][0] = mat[i][0];
        for(int j=0;j<m;j++)
            s[0][j] = mat[0][j];
        
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==1)
                    s[i][j] = min({s[i-1][j],s[i][j-1],s[i-1][j-1]})+1;
                else 
                    s[i][j] = 0;
            }
        }
        
        int ans = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,s[i][j]);
            }
        }
        return ans;
    }
};
Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.
