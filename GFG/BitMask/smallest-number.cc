// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
       if(S > D*9) return "-1";

        int res[D];
        S-=1;
        for(int i=D-1;i>=0;i--){
            if(S>9){
                res[i] = 9;
                S-=9;
            }else{
                res[i] = S;
                S = 0;
            }
        }
        res[0] += 1;
        string a = "";
        for(int i=0;i<D;i++) a += res[i]+'0';
        return a;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends
