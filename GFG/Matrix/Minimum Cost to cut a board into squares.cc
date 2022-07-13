// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort(X.begin(),X.end(),greater<>());
        sort(Y.begin(),Y.end(),greater<>());
        int i=0,j=0;
        int hor=1,ver=1;
        int cost=0;
        while(i<M && j<N){
            if(X[i]<=Y[j]){
                cost += (Y[j++]*hor);
                ver++;
            }else if(X[i]>Y[j]){
                cost += (X[i++]*ver);
                hor++;
            }
        }
        while(i<M){
            cost+=(X[i++]*ver);
                hor++;
        }
        while(j<N){
            cost+=(Y[j++]*hor);
                ver++;
        }
        return cost;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends
