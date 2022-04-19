

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
    TreeNode* first,*last,*prev;
    void inorder(TreeNode* root){
       if(!root) return;
        
        inorder(root->left);
        
        // if(first==nullptr and prev!=NULL and prev->val>root->val)
        //     first = prev,last = root;
        //  if(first!=nullptr and prev!=NULL and prev->val>root->val)
        //     last = root;
        if(prev!=nullptr and prev->val>root->val){
            if(first==nullptr)
                 first = prev,last = root;
            else
                 last = root;
        }
        
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        first = NULL; last = NULL; prev = NULL;
        inorder(root);
        swap(first->val,last->val);
    }
};
