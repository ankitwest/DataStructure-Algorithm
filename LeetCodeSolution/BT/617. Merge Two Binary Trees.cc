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
    TreeNode* merge(TreeNode* &root,TreeNode* a,TreeNode* b){
        if(!a and !b) return NULL;
        
        if(a and b){
            root = new TreeNode(a->val+b->val);
            merge(root->left,a->left,b->left);
            merge(root->right,a->right,b->right);
        }else if(a){
            root = new TreeNode(a->val);
            merge(root->left,a->left,NULL);
            merge(root->right,a->right,NULL);
        }else if(b){
            root = new TreeNode(b->val);
            merge(root->left,NULL,b->left);
            merge(root->right,NULL,b->right);
        }
        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root;
        return merge(root,root1,root2);
    }
    
};

class Solution {
public:
 TreeNode* mergeTrees(TreeNode* a, TreeNode* b) {
         if(!a) return b;
         
         if(a and b){
             a->val += b->val;
             a->left = mergeTrees(a->left,b->left);
             a->right = mergeTrees(a->right,b->right);
         }
         return a;
     }
};
