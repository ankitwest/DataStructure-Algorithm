class Solution {
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
      vector<int> dp(n, 1);
      
      for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
          if(arr[i] > arr[j] and 1 + dp[j] > dp[i]) 
                dp[i] = 1 + dp[j];
        }
      }
      return *max_element(dp.begin(), dp.end());
    }
};


//binary search
class Solution2 {
    public:
    int longestSubsequence(int n, int arr[])
    {
         vector<int> lis;  
         lis.push_back(arr[0]); 
        
        for(int i=1;i<n;i++){
            int num = arr[i];
            if(num > lis.back()){
                lis.push_back(num);
            }else{
                int idx = lower_bound(lis.begin(),lis.end(),num)-lis.begin();
                lis[idx] = num;
            }
        }
        return lis.size();    
    }
};


Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
