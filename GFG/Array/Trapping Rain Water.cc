N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
  

class Solution{
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
       long long int leftMax[n]; long long int rightMax[n];
       leftMax[0]=arr[0]; rightMax[n-1]=arr[n-1];
       
       for(int i=1;i<n;i++){
           leftMax[i]=max(leftMax[i-1],(long long)arr[i]);
       }
       for(int i=n-2;i>=0;i--){
           rightMax[i]=max(rightMax[i+1],(long long)arr[i]);
       }
       
       long long int ans=0;
       for(int i=0;i<n;i++){
           ans += (min(leftMax[i],rightMax[i]) - (long long)arr[i]);
       }
       return ans;;
    }
];




