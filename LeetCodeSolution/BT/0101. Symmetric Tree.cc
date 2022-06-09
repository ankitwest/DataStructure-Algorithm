class Solution {
public:
    bool mirror(TreeNode* root1,TreeNode* root2){
        if(!root1 and !root2) return true;
        if(!root1 or !root2) return false;
        if(root1->val != root2->val) return false;
        
        return mirror(root1->left,root2->right) and mirror(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        bool ans = mirror(root->left,root->right);
        return ans;
    }
};
