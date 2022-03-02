
class Solution{
public:
    //Function to find the maximum money the thief can get.
    vector<int> dp;
    int rec(int arr[],int i){
        if(i==0) return arr[i];
        if(i<0) return 0;
        
        if(dp[i]!=-1)
            return dp[i];
            
        int ans = 0;
        ans = max(arr[i]+rec(arr,i-2),rec(arr,i-1));
        
        return dp[i]=ans;
    }
    int FindMaxSum(int arr[], int n)
    {
        dp.resize(n+1,-1);
        return rec(arr,n-1);
    }
    };

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110
