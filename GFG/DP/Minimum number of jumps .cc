


// Possible or not
class Solution{
public:
    int minJumps(int arr[], int n){
        if(arr[0]==0) return -1;
        int maxReach = arr[0]+0;
      
    for(int i=1;i<=maxReach;i++){
          maxReach = max(maxReach,arr[i]+i);
          if(maxReach>=n-1) return 1;
      }
      
      return -1;
      }
    }
 };


class Solution{
public:
    int minJumps(int arr[], int n){
        int max_reach=0; int curr_reach=0;
         int jump=0;
        
        for(int i=0;i<n;i++){
            if(i>max_reach)
                return -1;
            max_reach=max(max_reach,arr[i]+i);
        
            if(curr_reach==i && i!=n-1){
                jump++;
                curr_reach=max_reach;
            }
        }
        return jump;
    }
 };


Example 1:

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
