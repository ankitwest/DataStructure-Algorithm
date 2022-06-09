class Solution {
public:
     int height(TreeNode* root,int &dia){
        if(!root) return 0;
        int lh = height(root->left,dia);
        int rh = height(root->right,dia);
        
        dia = max((lh + rh),dia);
        
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
       height(root,dia);
       return dia;
    }
};
