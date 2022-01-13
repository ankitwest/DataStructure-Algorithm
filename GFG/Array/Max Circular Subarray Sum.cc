class Solution{
    public:
    int kadane(int arr[],int n){
        int sum=arr[0]; int max_sum=arr[0];
        // int sum=0; int max_sum=0;
        for(int i=1;i<n;i++){
            // sum+=arr[i];
            // if(sum>max_sum) max_sum=sum;
            // if(sum<0) sum=0;
            
            sum = max(arr[i],sum+arr[i]);
            max_sum = max(max_sum,sum);
        }
        return max_sum;
    }
    int circularSubarraySum(int arr[], int n){
        
        int normal_sum = kadane(arr,n);
        if(normal_sum<0) 
            return normal_sum;
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            arr[i] = -arr[i];
        }
        int opposite_max_sum = kadane(arr,n);
        int circular_sum = sum + opposite_max_sum;
        
        // cout<<normal_sum<<" "<<circular_sum<<endl;
        
        return max(normal_sum,circular_sum);
    }
    };
