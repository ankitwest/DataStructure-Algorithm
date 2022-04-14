


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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        
        if(root->val>val) root->left = insertIntoBST(root->left,val);
        else if(root->val<val) root->right = insertIntoBST(root->right,val);
        
        return root;        
    }
};


// Iterative 

class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if root is None: return TreeNode(val)
        node = root
        
        while True:
            if node.val>val:
                if node.left is not None:
                    node = node.left
                else:
                    node.left = TreeNode(val)
                    break
            else:
                if node.right is not None:
                    node = node.right
                else:
                    node.right = TreeNode(val)
                    break
                    
        return root
