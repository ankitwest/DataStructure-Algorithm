class Solution{
public:	
	// simple array forward and backward
	// because lis is subsequence but bitoonic is continuous
	int bitonic(vector<int> arr, int n) {
        vector<int> left(n,1); vector<int> right(n,1);
        
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1])
                left[i] =  1 + left[i-1];
            else
                left[i] = 1;
        }
        
         for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1])
                right[i] =  1 + right[i+1];
            else
                right[i] = 1;
        }

        // for(int i=0;i<n;i++) cout<<left[i]<<" "; cout<<endl;
        // for(int i=0;i<n;i++) cout<<right[i]<<" "; cout<<endl;
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,left[i] + right[i] - 1);
        }
        return ans;
	}
};

class Solution2{
public:
// lis M-2 dp
	int bitonic(vector<int> arr, int n) {
        vector<int> dp_left(n,1); vector<int> dp_right(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>=arr[j] and dp_left[j] + 1 > dp_left[i])
                    dp_left[i] = 1 + dp_left[j];
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[i]>=arr[j] and dp_right[j] + 1 > dp_right[i])
                    dp_right[i] = 1 + dp_right[j];
            }
        }

        // for(int i=0;i<n;i++) cout<<dp_left[i]<<" "; cout<<endl;
        // for(int i=0;i<n;i++) cout<<dp_right[i]<<" "; cout<<endl;
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,dp_left[i] + dp_right[i] - 1);
        }
        return ans;
	}
};

N = 6
Arr[] = {12, 4, 78, 90, 45, 23}
Output: 5
Explanation: In the given array, 
bitonic subarray is 4 <= 78 <= 90
>= 45 >= 23.
Example 2:

Input:
N = 4
Arr[] = {10, 20, 30, 40}
Output: 4
Explanation: In the given array, 
bitonic subarray is 10 <= 20 <=
30 <= 40.
