class Solution{
public:
    int search(int A[], int l, int h, int key){
        // int low = l;int high = h; 
        while(l<=h){
            int mid = (l+h)/2;
            if(A[mid] == key)
                return mid;
            else if(A[l] <= A[mid]){
                if(A[l]<=key and key<=A[mid])
                    h = mid-1;
                else
                    l = mid+1;
            }else if(A[mid] <= A[h]){
                if(A[mid]<=key and key<=A[h])
                    l = mid+1;
                else 
                    h = mid-1;
            }
        }
        return -1;
    }
     
 };


Input:
N = 9
A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
key = 10
Output:
5
Explanation: 10 is found at index 5.
  
  
  
  
  
  
  
Find the pivot element in the sorted and rotated array

int findPivotElement(int arr[], int l, int h, int key){
     while(l<=h){
        int mid = (l + h) / 2;
        if (h == l)
            return l;
        if (mid < h && arr[mid] > arr[mid+1])
            return mid;
        if (mid > l && arr[mid] < arr[mid-1])
            return (mid - 1);
        if (arr[l] >= arr[mid])
            return h = mid-1;
        else 
            return l = mid+1;
        }
     return -1;
     }
