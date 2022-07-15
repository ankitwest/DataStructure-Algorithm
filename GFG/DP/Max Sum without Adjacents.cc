class Solution1{
public:	
	// calculate the maximum sum with out adjacent
	int N ;
	int dp[1000006];
	int solve(int *arr,int i){
	    if(i>=N) return 0;
	    if(i==N-1) return arr[N-1];

	    if(dp[i]!=-1)
	        return dp[i];
	    
	    int take = arr[i] + solve(arr,i+2);
	    int noTake = 0 + solve(arr,i+1);
	    
	    return dp[i] = max(take,noTake);
	}
	int findMaxSum(int *arr, int n) {
	    N = n;
	    memset(dp,-1,sizeof(dp));
	    return solve(arr,0);
	}
};

class Solution2{
public:	
    int findMaxSum(int *arr, int n) {
	    int dp[1000006];
	    memset(dp,-1,sizeof(dp));
	    
	    dp[0] = arr[0];
	    
	    for(int i=1;i<n;i++){
	        int take = arr[i] + ((i>=2)?dp[i-2]:0);
	        int notTake = 0 + dp[i-1];
	        
	        dp[i] = max(take,notTake);
	    }
	    return dp[n-1];
	}
};

class Solution{
public:	
    int findMaxSum(int *arr, int n) {
	   int prev2 = 0; int prev = arr[0];
	   int curr = 0;
	    
	    for(int i=1;i<n;i++){
	        int take = arr[i] + prev2;
	        int notTake = 0 + prev;
	        
	        curr = max(take,notTake);
	        prev2 = prev; prev = curr;
	    }
	    return prev;
	}
};
