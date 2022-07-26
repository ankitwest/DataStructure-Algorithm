

class Solution{
  public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int i=0,l=0; int maxi = 0;
        int zero = 0;
        while(i<n){
            if(arr[i]==0) zero++;
            
            while(l<i and zero>m){
                if(arr[l]==0) zero--;
                l++;
            }
            maxi = max(maxi,i-l+1);
            i++;
        }
        return maxi;
    }  
};
