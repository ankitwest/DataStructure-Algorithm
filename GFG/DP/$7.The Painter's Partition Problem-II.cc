class Solution
{
    bool check(long long  mid,int arr[],long long  n,long long  k){
        long long sum = 0;  long long  cnt = 1;
        for(int i=0;i<n;i++){
            if(arr[i]>mid) return false;
            if(sum + arr[i] > mid){
                cnt++;
                sum = arr[i];
            }else{
                sum += arr[i];
            }
            if(cnt>k) return false;
        }
        return true;
    }
  public:
    long long minTime(int arr[], int n, int k)
    {
       long long sum = accumulate(arr,arr+n,0LL);
       long long maxi = *max_element(arr,arr+n);
       
       long long ans = -1;
       long long low = maxi; long long high = sum;
       while(low<=high){
           long long mid = low + (high - low)/2;
           if(check(mid,arr,n,k)){
               ans = mid;
               high = mid - 1;
           }else{
               low = mid + 1;
           }
       }
       return ans;
    }
};
