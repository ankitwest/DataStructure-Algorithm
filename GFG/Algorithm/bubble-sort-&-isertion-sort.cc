void bubbleSort(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1-i;j++){
                if(arr[j]>arr[j+1]){
                    swap(&arr[j],&arr[j+1]);
                } 
            }
        }
    }

Expected Time Complexity: O(N^2).
    
    
    
    //Insertion Sort
    
    void insertionSort(int arr[], int n)
    {
        int key=0;
        for(int i=1;i<n;i++){
            key=arr[i];
            int j=i-1;
            while(j>=0 and arr[j]>key){
               arr[j+1]=arr[j]; j--;
            }
            arr[j+1]=key;
        }
    }

Expected Time Complexity: O(N^2).
