


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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        auto solve = [&low,&high](auto solve,TreeNode* root) -> TreeNode*{
            if(!root) return NULL;
            
            if(root->val<low) 
                return solve(solve,root->right);
            if(root->val>high) 
                return solve(solve,root->left);
            
            root->left = solve(solve,root->left);
            root->right = solve(solve,root->right);
            
            return root;
        };
        return solve(solve,root);
    }
};

Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
