class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int maxi = 0;
        
        int rightMax[n];
        rightMax[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],arr[i]);
        }
        // for(int i=0;i<n;i++) cout<<rightMax[i]<<" ";  cout<<endl;
        
        int i=0,j=0;
        while(i<n and j<n){
            if(arr[i]<=rightMax[j]){
                maxi = max(maxi,j-i);
                j++;
            }else{
                i++;
            }
        }
        return maxi;
    }

};


O(N)
