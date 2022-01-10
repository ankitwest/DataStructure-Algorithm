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

	
	
	
	
	
QQQ.   Longest Span in two Binary Arrays
	
	int longestCommonSum(bool arr1[], bool arr2[], int n) {
        int arr[n];
        for(int i=0;i<n;i++) 
            arr[i] = arr1[i]-arr2[i];
        
       unordered_map<int,int> m;
	   int sum = 0;  int len = 0;
	   
	   for(int i=0;i<n;i++){
	       sum += arr[i];
	       
	       if(sum==0){
	           len = i+1;}
	       else if(m.find(sum)!=m.end()){
	           len = max(len,i-m[sum]);
	       }else{
	           m[sum]=i;
	       }
	       
	   }
	   return len;
    }



N = 6
Arr1[] = {0, 1, 0, 0, 0, 0}
Arr2[] = {1, 0, 1, 0, 0, 1}
Output: 4
Explanation: The longest span with same
sum is from index 1 to 4 following zero 
based indexing.
