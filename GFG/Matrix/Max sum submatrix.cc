vector<int> maxSubMatrixSumQueries(vector<int> mat[], int n, int m,
                                   vector<pair<int, int>> &queries, int q) {
        vector<int> ans;
        int pre_sum[n + 1][m + 1];
        

        for (int i = 0; i <= n; i++)
            pre_sum[i][0] = 0;
        // make the right most row 0
        for (int i = 0; i <= m; i++)
            pre_sum[0][i] = 0;
        
        // calculate the presum of the matrix
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                pre_sum[i][j] = mat[i - 1][j - 1] + pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1];
        }
        
        for (auto p : queries)
        {
            int maxi = 0, temp, r = p.first, c = p.second;
            for (int i = r; i <= n; i++)
            {
                for (int j = c; j <= m; j++)
                {
                    temp = pre_sum[i][j] - pre_sum[i][j - c] - pre_sum[i - r][j] + pre_sum[i - r][j - c];
                    maxi = max(maxi,temp);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
  
  
  Input:
N = 3, M = 4
mat[][] = {{1, 2, 3, 9}, 
           {4, 5, 6, 2}, 
           {8, 3, 2, 6}}
Q = 3
Queries[] = {(1, 1), (2, 2), (3, 3)}

Output: 9 20 38

Example 3:

Input:
N = 2, M = 7
mat[][] = {{49, 44, 46, 22, 24, 11, 2}, 
           {5, 25, 24, 28, 20, 47, 47}}
Q = 1
Queries = {(2, 1)}

Output: 70
