// Amazon Interview Series

class Solution{
public:	
vector<int> dp;
	// calculate the maximum sum with out adjacent
	int solve(int arr[],int n,int ind){
	    if(ind==n) return 0;
	    if(ind==n-1) return arr[n-1];
	    
	    if(dp[ind]!=-1) return dp[ind];
	    
	    //take
	    int sum1 = 0; int sum2 =0;
	     sum1 = arr[ind] + solve(arr,n,ind+2);
	    
	    //not take
	    sum2 = 0 + solve(arr,n,ind+1);
	    
	    return dp[ind]=max(sum1,sum2);
	}
	int findMaxSum(int *arr, int n) {
	    dp.resize(n+1,-1);
	    return solve(arr,n,0);
	}
};
