class Solution{
  public:
 // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    
    long merge(long long a[],long long temp[],int l,int m,int r){
        long long c = 0; 
        int i=l,j=m+1; int k = l; int j2 = j;
        
        while(i<=m and j<=r){
            if(a[i] <= a[j]){
                temp[k++] = a[i++];
            }else{
                temp[k++] = a[j++];
                c += m+1-i;
            }
        }
        
        while(i<=m){
            temp[k++] = a[i++];
        }
         while(j<=r){
            temp[k++] = a[j++];
        }
        
        for(int i=l;i<=r;i++)
            a[i] = temp[i];
        
        return c;
  }
    long mergeSort(long long arr[],long long temp[],int l,int r){
        long long cnt = 0;
        if(l<r){
            long long m = (l+r)/2;
            cnt += mergeSort(arr,temp,l,m);
            cnt += mergeSort(arr,temp,m+1,r);
            cnt += merge(arr,temp,l,m,r);
        }
        return cnt;
    }
    long mergeSortInitial(long long arr[],int l,int r){
        long long temp[r-l+1];
        return mergeSort(arr,temp,l,r);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // int an = mergeSortInitial(arr,0,(int)(N-1));
        // for(int i=0;i<N;i++) cout<<arr[i]<<" "; cout<<endl;
        // return an;
        return mergeSortInitial(arr,0,(int)(N-1));
    }
};
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
