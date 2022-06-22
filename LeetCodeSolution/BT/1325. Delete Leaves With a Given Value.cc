//postorder
class Solution {
    TreeNode* solve(TreeNode* root,int target){
        if(!root) return NULL;
        
        root->left = solve(root->left,target);
        root->right = solve(root->right,target);
        
        if(root->val == target and root->left == NULL and root->right == NULL) return NULL;
        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root,target);
    }
};
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
