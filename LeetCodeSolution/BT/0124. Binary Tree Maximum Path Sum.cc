class Solution {
private:
    int max_path_sum = INT_MIN;
    int pathSum(TreeNode* node){
        if(!node) return 0;
        
        int left_sum = max(0,pathSum(node->left));  // return the max_path_sum of left subtree
        int right_sum = max(0,pathSum(node->right));
        
        max_path_sum = max(max_path_sum, left_sum + right_sum + node->val);
        
        return node->val + max(left_sum,right_sum); // return the max_path_sum of called subtree
    }
public:
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return max_path_sum;
    }
};
