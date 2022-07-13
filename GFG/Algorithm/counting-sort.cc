// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        int n = arr.length();
        int count[256] = {0}; // 0 to 255 characters in ASCII
        char output[n];
        string res = "";
        
        for (int i = 0; i<n; i++)
            count[arr[i]]++;
        for (int i = 1; i<256; i++)
            count[i] += count[i-1];
            
        for (int i = n-1; i>=0; i--){
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
        for (int i = 0; i<n; i++)
            res += output[i];
        return res;
    }
};

Input:
N = 5
S = "edsab"
Output:
abdes
Explanation: 
In lexicographical order, string will be 
abdes.









// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
