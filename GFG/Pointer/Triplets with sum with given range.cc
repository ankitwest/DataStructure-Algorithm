class Solution {
  public:
    int countTriplets(int arr[], int n, int l, int r) {
        sort(arr,arr+n);
        
        auto func = [&](int k){
            int cnt = 0;
            for(int i=0;i<n;i++){
                int l = i+1,r=n-1;
                while(l<r){
                    if(arr[i]+arr[l]+arr[r] > k) r--;
                    else cnt += r-l,l++;
                }
            }
            return cnt;
        };
        
        return func(r)-func(l-1);
    }
};
