


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,TreeNode* &ans){
        if(!root) return ;
        
        solve(root->left,ans);
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        solve(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* ans = new TreeNode(0);
        TreeNode* temp = ans;
        
        solve(root,ans);
        return temp->right;
    }a
};
