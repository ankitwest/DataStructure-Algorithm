class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;int j=n-1; int ans = 0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                i++,j--,ans++;
            }else if(nums[i]+nums[j]>k){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};


TC - O(NlogN)

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
  
  
  
  
  // Loop through the map
  class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        for(auto [x,y]:m){
            if(m.find(k-x)!=m.end())
                ans += min(m[k-x],y);
        }
        return ans/2;
    }
};



  // Loop through the number
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans = 0;
        unordered_map<int,int> m;
        
        for(auto a:nums){
           if(m[k-a] > 0){
               m[k-a]--;
               ans++;
            }else{
                m[a]++;
            }
        }
        return ans;
    };
