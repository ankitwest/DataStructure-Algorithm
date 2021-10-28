class Solution {
public:
    int ans=0;
    int findSum(TreeNode* root){
        if(!root) return 0;
        if(root->left){
            if(root->left->left and root->val%2==0) ans += root->left->left->val;
             if(root->left->right and root->val%2==0) ans += root->left->right->val;
                findSum(root->left);
        }
       if(root->right){
            if(root->right->left and root->val%2==0) ans += root->right->left->val;
        if(root->right->right and root->val%2==0) ans += root->right->right->val;
        findSum(root->right);
       }
    
        return ans;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return findSum(root);
    }
};
