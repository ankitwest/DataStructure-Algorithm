

class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    int sum = accumulate(arr,arr+n,0);
	    
	    int dp[n+1][sum/2+1];
	    memset(dp,0,sizeof(dp));
	    
	    
	   for(int i=0;i<=n;i++){
	       dp[i][0] = 1;
	   }
	   for(int j=1;j<=sum/2;j++){
	       dp[0][j] = 0;
	   }
	   //dp[0][0] = 1;
	   
	   bool take = false;
	   bool notTake = false;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum/2;j++){
	            if(j>=arr[i-1]) {
	                take = dp[i-1][j-arr[i-1]];
	            }
	                
	           notTake = dp[i-1][j];
	           dp[i][j] = take or notTake;
	        }
	    }
	    
	    int ans = INT_MAX;
	    for(int i=0;i<=sum/2;i++){
	        if(dp[n][i]==true){
	            ans = min(ans, sum - 2*i);
	        }
	    }
	    return ans;
	} 
};



Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   
  
  
Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4
