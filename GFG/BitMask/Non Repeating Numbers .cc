// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xxor = 0;
       for(int i=0;i<nums.size();i++)
           xxor^=nums[i];
       
       int two = ~xxor + 1;
       int bit = xxor & two;   // xxor & -xxor
       
       int x = 0; int y = 0;
       for(int i=0;i<nums.size();i++){
           if(bit&nums[i])
               x^=nums[i];
           else
               y^=nums[i];
       }
       if(x>y)
           return {y,x};
       return {x,y};
    }
};
/*
As 2 is present two times so getting xor with sum1 two times only the result 
3 is being stored in it and As 4 is also present two times thus getting 
xor with sum2 will cancel it’s value and thus only 5 will remain there.
*/

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
