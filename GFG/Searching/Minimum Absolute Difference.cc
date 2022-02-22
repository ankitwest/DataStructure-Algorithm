int kthDiff(int a[], int n, int k)
{
    sort(a,a+n);
    int high = a[n-1]-a[0];
    int low = a[1]-a[0];
    
    for(int i=2;i<n;i++)
        low = min(low,a[i]-a[i-1]);
        
    
    auto count = [&](int mid) {
        int total=0;
        for(int i=0;i<n;i++){
             int cnt = upper_bound(a+i,a+n,a[i]+mid) - (a+i);
            cnt--;  // upper_bound;
            total += cnt;
        }
        
        // int j=1;
        // int total = 0;
        // for(int i=0;i<n;i++){
        //     while(j<n and a[j]-a[i]<=mid)
        //         j++;
        //     j--; // one extra increase
        //     int cnt = j-i;
        //     total += cnt;
        // }
        
        return total>=k;
    };
    int ans=0;
    while(low<=high){
        int mid = (low+high)>>1;
        if(count(mid))  ans = mid,high = mid-1;
        else low = mid+1 ;
    }
    return ans;
}


Input : 
N = 4
A[] = {1, 2, 3, 4}
k = 3
Output : 
1 
Explanation :
The possible absolute differences are :
{1, 2, 3, 1, 2, 1}.
The 3rd smallest value among these is 1.
