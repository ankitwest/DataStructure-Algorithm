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



Minimum number of jumps 
class Solution{
  public:
    int minJumps(int arr[], int n){
        int reachable=0; int curr_reach=0;
         int jump=0;
        
        for(int i=0;i<n;i++){
            if(reachable<i) return -1;
            reachable=max(reachable,arr[i]+i);
        
            if(curr_reach==i){
                if(i==n-1) continue;
                jump++;
                curr_reach=reachable;
            }
        }
        return jump;
    }
};
