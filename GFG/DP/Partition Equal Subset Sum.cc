

class Solution{
public:
    int n=0;
    vector<vector<int>> dp;
    bool solve(int idx,int sum,int arr[]){
        if(sum==0)
            return true;
        if(sum<0)
            return false;
        if(sum!=0 and idx>=n)
            return false;
            
        if(dp[idx][sum]!=-1)
            return dp[idx][sum];
        
        bool a = solve(idx+1,sum-arr[idx],arr);
        bool b = solve(idx+1,sum,arr);
        
        bool ans = a or b;
        return dp[idx][sum] = ans;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr,arr+N,0);
        if(sum&1) return false;
        n = N;
        dp.resize(n+1,vector<int>(sum+1,-1));
        
        return solve(0,sum/2,arr);
    }
};


Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
