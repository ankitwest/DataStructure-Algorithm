
class Solution{
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int maxi = -1; int n,m;
    bool isValid(vector<vector<int>> &matrix,int a,int b){
        return a>=0 and b>=0 and a<n and b<m and matrix[a][b]==1;
    }
    void dfs(vector<vector<int>> &matrix, int i, int j, int xe, int ye,int ans){
        if(i==xe and j==ye){
            maxi = max(maxi,ans);
            return;
        }
        
        matrix[i][j] = 2;
        
        for(int k=0;k<4;k++){
            int a = i+dx[k];int b = j+dy[k];
            if(isValid(matrix,a,b)){
                dfs(matrix,a,b,xe,ye,ans+1);    
            }
        }
        matrix[i][j] = 1;
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xe, int ye)
    {
        n = matrix.size(); m = matrix[0].size();
        if(matrix[xs][ys]==0)
            return -1;
            
        int ans = 0;
        dfs(matrix,xs,ys,xe,ye,ans);
        return maxi;
    }
    };
Input:
{xs,ys} = {0,0}
{xd,yd} = {1,8}
matrix = 1 1 1 1 1 1 1 1 1 1
         1 1 0 1 1 0 1 1 0 1
         1 1 1 1 1 1 1 1 1 1
Output: 24
Explanation:
