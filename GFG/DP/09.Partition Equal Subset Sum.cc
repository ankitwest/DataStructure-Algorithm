

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

    
    
    
    
    
// Tabulation
class Solution{
public:
     int equalPartition(int N, int arr[]){
         int sum = accumulate(arr,arr+N,0);
        if(sum&1) return false;
        int n = N;
        vector<vector<int>> dp(n+1,vector<int>(sum/2+1));
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
         for(int j=0;j<=sum/2;j++){
             dp[0][j] = 0;
         }
         dp[0][0] = 1;
         
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                if(j>=arr[i-1])
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
                else 
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum/2];
     }
};
