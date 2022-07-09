// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long> > minpq;
        for(int i=0;i<n;i++){
            minpq.push(arr[i]);
        }
        long long sum=0;
        long long ans=0;
        long long a=0,b=0;
        
        while(minpq.size()>=2){
            a = minpq.top();minpq.pop();
            b = minpq.top();minpq.pop();
            sum = a+b;
            minpq.push(sum);
            ans += sum;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
  // } Driver Code Ends
