

class Solution {
public:
    vector<vector<int>> ans;
    void helper(int start,int end,vector<int>& v, int k, int sum) {
        if(sum == 0 && v.size() == k) {
            ans.push_back(v);
            return;
        }
        if(sum < 0 || v.size() > k) return;
        
        for(int i=start; i<=end; i++) {
            v.push_back(i);
            helper(i+1,end,v, k, sum-i);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        helper(1,9,v, k, n);
        return ans;
    }
};
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
