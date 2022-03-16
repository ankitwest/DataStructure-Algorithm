
vector<int> find(int arr[] , int n,int x)
  {
    auto first = [&](int arr[],int l,int h,int x){
        while(l<=h){
            int mid = l+(h-l)/2;
            if((mid==0 or arr[mid-1]<x) and (arr[mid]==x))
                return mid;
            else if(arr[mid]>=x)
                h = mid-1;
            else
                l = mid+1;
        }
        return -1;
    };
    auto last = [&](int arr[],int l,int h,int x){
        while(l<=h){
            int mid = l+(h-l)/2;
            if((mid==n-1 or x<arr[mid+1]) and (arr[mid]==x))
                return mid;
            else if(arr[mid]>x)
                h = mid-1;
            else
                l = mid+1;
        }
        return -1;
    };
    int a = first(arr,0,n-1,x);
    int b = last(arr,0,n-1,x);

    if(a==-1 and b==-1)
        return {-1,-1};
    return {a,b};
}
  





  Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last
             occurrence of 5 is at index 5.
