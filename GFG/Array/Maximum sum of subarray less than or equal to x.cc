	public:
	int findMaxSubarraySum2(long long arr[], int n, long long k)
	{
	    int sum = 0; int max_sum = -1;
	    int l = 0;
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	        while(sum > k){
	            sum -= arr[l];
	            l++;
	        }
	        max_sum = max(max_sum , sum);
	    }
	    return max_sum;
	}
	
	
	
	int findMaxSubarraySum(long long arr[], int n, long long k)
	{
	    set<int> s;
        int pre_sum = 0, ans = 0;
        s.insert(0);
        for(int i=0;i<n;i++)
        {
            pre_sum += arr[i];
            auto it = s.lower_bound(pre_sum - k);
            if (it != s.end())
                ans = max(ans, pre_sum - *it);
            if (ans == k)
                return k;
            s.insert(pre_sum);
        }
        return ans;
   }   



Input: N = 5, X = 11
arr[] = {1, 2, 3, 4, 5} 
Output:  10
Explanation: Subarray having maximum 
sum is {1, 2, 3, 4}.
 
Example 2:

Input: N = 5, X = 7
arr[] = {2, 4, 6, 8, 10} 
Output:  6
Explanation: Subarray having maximum 
sum is {2, 4} or {6}.
