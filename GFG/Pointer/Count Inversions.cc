
    long long cnt = 0;
    void merge(vector<long long> &a, int left, int mid, int right){
        vector<long long> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid and j <= right) {
            if (a[i] <= a[j]) { 
                temp[k++] = a[i++];
            }
            else {
                temp[k++] = a[j++];
                // only line responsible to update count, related to problem constraint, 
                // remaining part is just regular mergeSort 
                cnt += mid + 1 - i;
                
            }
        }
        while (i <= mid) {
            temp[k++] = a[i++];
        }
        while (j <= right) {
            temp[k++] = a[j++];
        }
        for (int i = left; i <= right; i++)
            a[i] = temp[i-left];
    }
    
    void merge_sort(vector<long long>& a,int left,int right){
        if(left < right){
            int mid = left + (right-left)/2;
            merge_sort(a, left, mid);
            merge_sort(a, mid+1, right);
            merge(a, left, mid, right);
        }
    }
public:
    long long int inversionCount(long long arr[], long long N)
    {
        int n = N;
        vector<long long> nums(n,0);
        for(int i=0;i<n;i++) nums[i] = arr[i];
        merge_sort(nums, 0, n-1);
        
        return cnt;
    }
};
