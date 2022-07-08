// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
     unordered_map<long,long> m;
        
     long count = 0;
     for(int i=0;i<n;i++){
         int rem = (A[i]%K + K)%K;
         if(rem==0) 
            count += m[rem];
         else 
            count += m[K-rem];
         m[rem]++;
     }
     return count;
    }
};
