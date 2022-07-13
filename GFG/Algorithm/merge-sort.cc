// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public: // TC - O(NlogN)
    void merge(int arr[],int left,int mid,int right)
    {
        int i,j,k;
        int n1 = mid-left+1;
        int n2 = right-mid;

        int leftarr[n1] , rightarr[n2];

        for(i=0;i<n1;i++) leftarr[i] = arr[left+i];
        for(j=0;j<n2;j++) rightarr[j] = arr[mid+1+j];

        i=0; j=0; k=left;
        while(i<n1 and j<n2){
            if(leftarr[i]<=rightarr[j]){
                arr[k++] = leftarr[i++];
            }else{
                arr[k++] = rightarr[j++];
            }
        }

        while(i<n1) 
            arr[k++] = leftarr[i++];
        while(j<n2) 
            arr[k++] = rightarr[j++];
    }

    void mergeSort(int arr[],int left,int right)
    {
        if(left>=right) return;

        int mid = (left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
};







// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
