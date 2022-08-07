
class Solution {
public:
    void solve(int i,vector<int>& coins,int target,vector<int> &v,vector<vector<int>> &ans){
        if(i==coins.size()){
            if(target==0){
                ans.push_back(v);
                return;
            }
        }
        
        if(i>=coins.size() or target<0)
            return ;
        
        v.push_back(coins[i]);
        solve(i,coins,target-coins[i],v,ans);  // we can take repeat candidates 
        v.pop_back();
        
        solve(i+1,coins,target,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> ans;  
        vector<int> v;
        
        solve(0,coins,target,v,ans);
        return ans;
    }
};


// Striver
TC : O(2^t * k) where t is the target, k is the average length ;
Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

  SC : O(k*x), k is the average length and x is the no. of combinations
  
  

// Q
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
  
  
// Output
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
