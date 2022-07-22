class Solution1 {
    vector<vector<long long>> dp;

    long long solve(int arr[],int i,int j){
        if(i>j) return 0;
        // if(i==j) return arr[i];
        // if(i==j+1) return max(arr[i],arr[j]);
        
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        // i -> i+1,j
        // j -> i,j-1
        long long choice1 = arr[i] + min(solve(arr,i+2,j), solve(arr,i+1,j-1));
        long long choice2 = arr[j] + min(solve(arr,i+1,j-1), solve(arr,i,j-2));
        
        return dp[i][j] = max(choice1, choice2);
    }
public:    
    long long maximumAmount(int arr[], int n){
        dp.resize(n,vector<long long>(n,-1));
        
        return solve(arr,0,n-1);
    }
};

//min part is optimal step of opponent but
//max part is optimal step of mine



//tabulation
class Solution {
public:
    long long maximumAmount(int arr[], int n){
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        
        //i is at left side of arr
        //j is at right side of same arr
        //then we should use gap method;
        
        for(int gap = 0;gap < n; gap++){
            int j = gap;
            for(int i = 0; j < n; i++,j++){
                if(i==j)
                    dp[i][j] = arr[i];
                // else if(i==j+1)
                //     dp[i][j] = max(arr[i],arr[j]);
                else{
                    long long choice1 = arr[i] + min( dp[i+2][j] , dp[i+1][j-1] );
                    long long choice2 = arr[j] + min( dp[i+1][j-1] , dp[i][j-2] );
                    
                    dp[i][j] = max(choice1, choice2);
                }

            }
        }
        
        return dp[0][n-1];
    }
    
};
