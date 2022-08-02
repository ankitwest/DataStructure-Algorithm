class Solution{
public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr,arr+n);
        int cnt=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int k=j+1;
                while(k < n and arr[i] + arr[j] > arr[k] )
                k++;
                
                cnt += k - j - 1;
            }
        }
        return cnt;
    }
    };
