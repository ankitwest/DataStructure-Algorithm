// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if(n&1) return false;
        
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            nums[i] = (nums[i]%k + k)%k;
            m[nums[i]]++;
        }
        if(m[0]&1) return false;
        
         for(int rem=1;rem<k;rem++){
            if(m[rem]!=m[k-rem]) return false;
        }
        
        return true;
    }
};

