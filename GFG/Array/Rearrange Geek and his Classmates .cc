class Solution {
  public:
    void prank(long long a[], int n){
        long long b[n];
        
        for(int i=0;i<n;i++){
            long long roll = a[i]; // his roll is sone else desk no
            long long desk = roll;
            b[i] = a[desk];
        }
        
        for(int i=0;i<n;i++) a[i]=b[i];
    }
};

Example 1:

Input:
N = 6
a[] = {0, 5, 1, 2, 4, 3}
Output: 0 3 5 1 4 2
Explanation: After reshuffling, the modified 
position of all the students would be 
{0, 3, 5, 1, 4, 2}.

Example 2:

Input:
N = 5
a[] = {4, 3, 2, 1, 0}
Output: 0 1 2 3 4 
Explanation: After reshuffling, the modified 
position of all the students would be 
{0, 1, 2, 3, 4}.
