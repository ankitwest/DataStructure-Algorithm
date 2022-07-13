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
