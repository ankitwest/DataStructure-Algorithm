
class Solution{
    public:
    void sort012(int a[], int n)
    {
        // Dutch national flag algorithm
        int low = 0;int mid = 0; int high = n-1;
        while(mid<=high){
            if(a[mid]==0)
                swap(a[low],a[mid]),low++,mid++;
            else if(a[mid]==1)
                mid++;
            else if(a[mid]==2)
                swap(a[mid],a[high]),high--;
        }
    }
    };Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
