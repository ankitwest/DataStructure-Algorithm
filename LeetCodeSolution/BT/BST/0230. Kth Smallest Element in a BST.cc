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
//     vector<int> ans;
//     void inorder2(TreeNode* root){
//         if(root==NULL)
//             return ;
        
//         inorder2(root->left);
//         ans.push_back(root->val);
//         inorder2(root->right);
//     }
    void inorder(TreeNode* root,vector<int> &v){
        if(root==NULL)
            return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        inorder(root,v);
        return v[k-1];
    }
};

