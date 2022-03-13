class Solution
{
    public:
    int Maxdistance (int a[], int n)
    {
        int i=0,j=0; int ans=0;
        while(j<n){
            if(j<n-1 and a[j]<=a[j+1]) j++;
            else if(i>=1 and a[i-1]>=a[i]) i--;
            else {
                j=j+1;
                i=j;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};

O(N^2)
    
   

Input: 
N = 5
A[] = {1,2,3,4,5}
Output: 4
Explanation: 
Geek and his friend will start at 1st index.
While geek move his car to 5th index , his 
friend will keep his car at 1st.
    
    
    
    
    // M-2
   class Solution 
    {
    public:
    // 5 4 3 2 1
    int Maxdistance (int a[], int n)
    {
        int i=0,j=0; int ans=0; bool has_moved_right = false;
        while(j<n){
            if(j<n-1 and a[j]<=a[j+1]) {
                j++;
                has_moved_right = true;
            }else if(i>=1 and a[i-1]>=a[i]){
                 i--;
            }
            else {
                ans = max(ans,j-i);
                j=j+1;
                if(has_moved_right){
                    i=j;
                }
            }
        }
        return ans;
    }

       
       O(N)
