


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
//     TreeNode* solve(TreeNode* root,int& sum){
//         if(!root) return NULL;
        
//         solve(root->right,sum);
//         sum += root->val;
//         root->val = sum;
//         solve(root->left,sum);
        
//         return root;
//     }
    
//     int sum = 0;
//     TreeNode* solve2(TreeNode* root){
//         if(!root) return NULL;
        
//         solve2(root->right);
//         sum += root->val;
//         root->val = sum;
//         solve2(root->left);
        
//         return root;
//     }
    
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        int sum=0;
        auto solve = [&](auto solve,TreeNode* root,int& sum)->TreeNode*{
             if(!root) return NULL;
            
            solve(solve,root->right,sum);
            sum += root->val;
            root->val = sum;
            solve(solve,root->left,sum);
            
            return root;
        };
        return solve(solve,root,sum);
    }
    
};
