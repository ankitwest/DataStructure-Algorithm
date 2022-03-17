class Solution{
public:
    int count(int n, vector<int> arr,int X)
    {
         int bitsetinX = 0; int ans = INT_MAX;
         for(int i=31;i>=0;i--){
             int bit = 1<<i;
             if((X&bit)>0){  // useless
                 bitsetinX |= bit;
             }else{   // gold
                int temp = bitsetinX | bit; 
                int dontModify=0;
                for(int i=0;i<n;i++){
                    if((arr[i]&temp)==temp) dontModify++;
                }
                ans = min(ans,n-dontModify);
            }
         }
         return ans;
    }
    };



Example 1:

Input:
N = 4, X = 2
A[] = {3, 1, 2, 7}
Output: 
2
Explanation: 
After performing two operations:
Modified array: {3, 3, 11, 7} 
Now, Bitwise AND of all the elements
is 3 & 3 & 11 & 7 = 3 
Example 2:

Input:
N = 3, X = 1
A[] = {2, 2, 2}
Output: 
0
