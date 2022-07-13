class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        int ans = 0; int sum = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
                sum -= 1;
            else if(arr[i]==1)
                sum += 1;
            
            if(m.count(sum))
                ans += m[sum],m[sum]++;
            else
                m[sum]++;
        }
        return ans;
    }
};

Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)

  
  
  
  
  Q   Largest subarray of 0's and 1's
  
  class Solution {
  public:
    int maxLen(int arr[], int n)
    {
        int max_len = 0; int sum = 0;
        unordered_map<int,int> m;
        m[0] = -1;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
                sum -= 1;
            else if(arr[i]==1)
                sum += 1;
                
            if(m.count(sum))
                max_len = max(max_len,i - m[sum]);
            else 
                m[sum] = i;
        }
        return max_len;
    }
};
