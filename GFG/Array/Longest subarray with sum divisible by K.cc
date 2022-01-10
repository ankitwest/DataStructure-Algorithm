int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	   unordered_map<int,int> m;
	   int sum = 0; int rem = 0; int len = 0;
	   
	   for(int i=0;i<n;i++){
	       sum += arr[i];
	       rem = ((sum%k)+k)%k;
	       
	       if(rem==0){
	           len = i+1;}
	       else if(m.find(rem)!=m.end()){
	           len = max(len,i-m[rem]);
	       }else{
	           m[rem]=i;
	       }
	       
	   }
	   return len;
	}




A[] = {2, 7, 6, 1, 4, 5}
K = 3
Output: 4
Explanation:The subarray is {7, 6, 1, 4}
with sum 18, which is divisible by 3.
