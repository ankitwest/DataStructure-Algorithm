
class Solution {
public:
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        int h = height(root);
        return ans;
    }
    int height(TreeNode* root){
        if(!root) return 0;
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        if(abs(lh-rh)>1) {
            ans = false;
        }
        
        return max(lh,rh)+1;
    }
};
