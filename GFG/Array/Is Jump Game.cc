class Solution{
  public:
    int canReach(int arr[], int n) {
       int reachable = 0;
       for(int i=0;i<n;i++){
           if(reachable<i)
                return false;
            reachable = max(reachable,i+arr[i]);
       }
       return true;
    }
 };
