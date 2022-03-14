class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        if(n==1) return 0;
        sort(arr,arr+n);
        int maxi = 0;int mini = 0;
        int ans = arr[n-1] - arr[0];
        
        
        for(int i=1;i<n;i++){
            if(arr[i]-k<0) continue;
            mini = min(arr[0]+k,arr[i]-k);
            maxi = max(arr[n-1]-k,arr[i-1]+k);

            ans = min(ans,maxi-mini);
        }
        return ans;
    }
};

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.
