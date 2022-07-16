class Solution{
public:
    int gameOfXor(int N , int A[]) {
        int ans = 0;
        for(int i=0;i<N;i++){
            int freq = (i+1)*(N-i);
            if(freq&1)
            ans = ans ^ A[i];
        }
        return ans;
    }
    
    
    int gameOfXor(int N,int A[]){
         if(N%2==0)
           return 0;
       int ans=0;
       for(int i=0;i<N;i=i+2){
           ans=ans^A[i];
       }
       return ans;
    }
};



Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

    
    
    
    https://www.geeksforgeeks.org/xor-of-xors-of-all-sub-matrices/?ref=rp
    Matrix
    
    
    
    // C++ program to find the XOR of XOR's of
// all submatrices

#include <iostream>
using namespace std;

#define n 3

// Function to find to required
// XOR value
int submatrixXor(int arr[][n])
{
	int ans = 0;

	// Nested loop to find the
	// number of sub-matrix each
	// index belongs to
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Number of ways to choose
			// from top-left elements
			int top_left = (i + 1) * (j + 1);

			// Number of ways to choose
			// from bottom-right elements
			int bottom_right = (n - i) * (n - j);

			if ((top_left % 2 == 1) && (bottom_right % 2 == 1))
				ans = (ans ^ arr[i][j]);
		}
	}

	return ans;
}

// Driver Code
int main()
{
	int arr[][n] = { { 6, 7, 13 },
					{ 8, 3, 4 },
					{ 9, 7, 6 } };

	cout << submatrixXor(arr);

	return 0;
}
