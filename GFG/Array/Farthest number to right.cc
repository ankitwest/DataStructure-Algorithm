class Solution{
public:
    vector<int> farNumber(int n,vector<int> arr){
        vector<int> rightMin(n,0); 
        rightMin[n-1] = arr[n-1]; //min
       for(int i=n-2;i>=0;i--){
           rightMin[i] = min(arr[i],rightMin[i+1]);
       }
       
       vector<int> v;
       for(int i=0;i<n;i++){
           int low = i+1; int high = n-1; int ans = -1;
           while(low<=high){
               int mid = (low+high)/2;
               if(rightMin[mid] < arr[i]){
                   ans = mid;
                    low = mid+1;
               }else{
                   high = mid-1;
               }
           }
           v.push_back(ans);
       }
       return v;
    } 
    };
