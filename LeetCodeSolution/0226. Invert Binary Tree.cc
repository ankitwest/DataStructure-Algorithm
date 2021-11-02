class Solution {
public:
    void invert(TreeNode* &root){
    if(!root) return ;
        
    invert(root->left);
    invert(root->right);
    swap(root->left,root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        invert(root);
        return root;
    }
};
