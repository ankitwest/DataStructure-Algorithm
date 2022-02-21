
class Solution{
  public:
    int majorityElement(int a[], int n)
    {
        int maj_index = 0,cnt=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[maj_index]) cnt++; else cnt--;
            if(cnt==0) maj_index = i,cnt=1;
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==a[maj_index]) cnt++;
        }
        if(cnt>n/2) return a[maj_index];
        return -1;
    }
  };

TC : O(N) from O(N^2)


Moore Voting Algorithm  
  
  
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.
