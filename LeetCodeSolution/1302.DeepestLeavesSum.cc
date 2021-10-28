class Solution {
public:
    map<int,int> m;
    void dfs(int d,TreeNode* root){
        if(!root) return;
        if(!root->left and !root->right){
            m[d]+=root->val;
        }
        dfs(d+1,root->left);
        dfs(d+1,root->right);
    }
    int deepestLeavesSum(TreeNode* root) {
       dfs(0,root);
        int ans =0;
        for(auto x:m){
            ans = x.second;
        }
        return ans;   
    }
};
