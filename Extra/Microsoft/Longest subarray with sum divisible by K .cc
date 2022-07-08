class Solution{
public:	
	int longSubarrWthSumDivByK22(int arr[], int n, int k)
	{
	   unordered_map<int,int> m;
	   int sum = 0; int max_len = 0;
	   
	   m[0] = -1;
	   for(int i=0;i<n;i++){
	       sum += arr[i];
	       int rem = sum%k; if(rem<0) rem += k;
	       
	       if(m.find(rem)!=m.end())
	           max_len = max(max_len, i-m[rem]);
	       else
	           m[rem] = i;
	   }
	   return max_len;
	}
	
	
	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	   unordered_map<int,int> m;
	   int sum = 0; int max_len = 0;
	   
	   for(int i=0;i<n;i++){
	       sum += arr[i];
	       int rem = (sum%k + k)%k;
	       
	       if(rem==0)
	           max_len = max(max_len, i+1);
	       
	       if(m.find(rem)!=m.end())
	           max_len = max(max_len, i-m[rem]);
	       else
	           m[rem] = i;
	   }
	   return max_len;
	}
};

with neg nos;
