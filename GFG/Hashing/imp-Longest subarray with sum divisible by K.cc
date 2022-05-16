


class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	   unordered_map<int,int> m;
	   int sum = 0; int ans = 0;
	   
	   m[0] = -1;
	   for(int i=0;i<n;i++){
	       sum += arr[i];
	       int rem = sum%k; if(rem<0) rem += k;
	       
	       if(m.find(rem)!=m.end())
	           ans = max(ans,i-m[rem]);
	       else
	           m[rem] = i;
	   }
	   return ans;
	}
};


Example 1:

Input:
A[] = {2, 7, 6, 1, 4, 5}
K = 3
Output: 4
Explanation:The subarray is {7, 6, 1, 4}
with sum 18, which is divisible by 3.
Example 2:

Input:
A[] = {-2, 2, -5, 12, -11, -1, 7}
K = 3
Output: 5
Explanation:
The subarray is {2,-5,12,-11,-1} with
sum -3, which is divisible by 3.
