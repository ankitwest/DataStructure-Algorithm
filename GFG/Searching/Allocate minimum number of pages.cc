class Solution{
 public:
    //Function to find minimum number of pages.
    bool isPossible(int arr[],int n,int k,int mini){
        int req=1;
        int curr_sum = 0;
        for(int i=0;i<n;i++){
            if(curr_sum+arr[i]>mini){
                req++;
                curr_sum = arr[i];
            }else
                curr_sum += arr[i];

            if(req>k)
                return false;
        }
        return true;
    }
    int findPages(int arr[], int n, int k) 
    {
        int sum = accumulate(arr,arr+n,0);

        int low,high,mid;
        int ans=0;
        low = 0,high = sum;
        while(low<=high){
            mid = (low+high)/2;
            if(isPossible(arr,n,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    };
