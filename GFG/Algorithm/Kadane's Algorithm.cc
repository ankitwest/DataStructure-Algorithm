
class Solution{
public:
long long maxSubarraySum(int arr[], int n){
        
        int maxi = INT_MIN; int sum=0;
        int start = 0;int end = 0; int s = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum>maxi) {
                maxi = sum;
                start = s;
                end = i;
            }
            if(sum<0) {
                sum=0;
                s = i + 1;
            }
        }
        cout<< start<<" "<<end<<endl;
        return maxi;
    }
};

    
    
class Solution{
public:
  long long maxSubarraySum(int arr[], int n){
        
        int sum = arr[0];
        int max_sum = sum;
        if(sum<0) sum=0;
        
        for(int i=1;i<n;i++){
            sum += arr[i];
            if(sum>max_sum) max_sum = sum;
            if(sum<0) sum=0;
        }
        return max_sum;
    }
};
