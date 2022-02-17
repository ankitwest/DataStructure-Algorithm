class Solution {
public:
    void solve(int i,vector<int>& coins,int target,vector<int> &v,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        if(i>=coins.size() or target<0)
            return ;
        
        v.push_back(coins[i]);
        solve(i,coins,target-coins[i],v,ans);
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
Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
