
class Solution1 {
bool ans = true;
    int height(TreeNode* root){
        if(!root) return 0;
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        if(abs(lh-rh)>1) {
            ans = false;
        }
        
        return max(lh,rh) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h = height(root);
        return ans;
    }

};

/*
[1,2,2,3,3,null,null,4,4]
[1,2,2,3,null,null,3,4,null,null,4]

*/


without global variable

class Solution {
    int height(TreeNode* root){
        if(!root) return 0;
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        if(lh==-1 or rh==-1 or abs(lh-rh)>1) return -1;
        
        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h = height(root);
        return h == -1 ? 0 : 1;
    } 
};
