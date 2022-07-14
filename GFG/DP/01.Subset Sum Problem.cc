

class Solution1{   
public:
    vector<vector<int>> dp;
    bool solve(vector<int> arr,int i,int sum){
        if(i>=arr.size() and sum>0)
            return false;
        if(sum==0)
            return true;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
            
        bool ans = false;
        if(arr[i]<=sum){
            ans = solve(arr,i+1,sum-arr[i]) or solve(arr,i+1,sum);
        }else{
            ans = solve(arr,i+1,sum);
        }
        
        dp[i][sum] = ans;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        dp.resize(arr.size()+1,vector<int>(sum+1,-1));
        
        return solve(arr,0,sum);
    }
};

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));

           for(int i=0;i<=n;i++){
               for(int j=0;j<=sum;j++){
                     if(i==0)
                       dp[i][j]= false;
                     if(j==0)
                       dp[i][j] = true;
                 }
           }
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=sum;j++){
               if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j-arr[i-1]] or dp[i-1][j];
               else
                  dp[i][j]=dp[i-1][j];
           }
       }
       return dp[n][sum];
    }
};
