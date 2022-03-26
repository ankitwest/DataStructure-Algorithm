class Solution {
public:
    // here i is increased and called instead of idx
    vector<vector<int>> ans;
    void helper(int idx,int n,int k,vector<int>& temp){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            helper(i+1,n,k,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        helper(1,n,k,temp);
        return ans;
    }
};



Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
