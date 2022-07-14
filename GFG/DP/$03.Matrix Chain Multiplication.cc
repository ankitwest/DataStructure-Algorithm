class Solution{
  public:
  int dp[105][105];
    int matrixChainMulti(int arr[],int i,int j){
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int mini = INT_MAX;
        
        for(int k=i;k<j;k++){
            int temp = matrixChainMulti(arr,i,k) + matrixChainMulti(arr,k+1,j) + arr[i]*arr[j+1]*arr[k+1];
            mini = min(mini,temp);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int n, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return matrixChainMulti(arr,0,n-2);
    }
};



Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)


Constraints: 
2 ≤ N ≤ 100
1 ≤ arr[i] ≤ 500
  
  
 
  Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.
  
  
  
  
  
  class Solution{
  public:
  int solve(int arr[],int n){
        vector<vector<int>> dp(n-1,vector<int>(n-1,0));
        int l = n-1;
        for(int g=0;g<dp.size();g++){
            for(int i=0,j=g;j<dp.size();i++,j++){
                if(g==0)
                    dp[i][j]=0;
                 else if(g==1)
                    dp[i][j]=arr[i]*arr[j+1]*arr[j];
                else{
                    int mini = INT_MAX;
                    for(int k=i;k<j;k++){
                        //left - i to k and right - k+1 to j
                        int lc = dp[i][k];
                        int rc = dp[k+1][j];
                        int mc = arr[i]*arr[k+1]*arr[j+1];
                        int tc = lc + rc + mc;
                        mini = min(mini,tc);
                    }
                    dp[i][j] = mini;
                }
            }
        }
        
        return dp[0][dp.size()-1];
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        return solve(arr,n);
    }
  };




Better Iterative 
// See the Cormen book for details of the
// following algorithm
#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChainOrder(int p[], int n)
{

	/* For simplicity of the program, one
	extra row and one extra column are
	allocated in m[][]. 0th row and 0th
	column of m[][] are not used */
	int m[n][n];

	int i, j, k, L, q;

	/* m[i, j] = Minimum number of scalar
	multiplications needed to compute the
	matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying
	// one matrix.
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, size);

	getchar();
	return 0;
}

// This code is contributed
// by Akanksha Rai

