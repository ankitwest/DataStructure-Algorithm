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
    TreeNode* rec(vector<int>& preorder,int &i,int max_val){
        if(i==preorder.size() or preorder[i]>max_val) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        
        root->left = rec(preorder,i,root->val);
        root->right = rec(preorder,i,max_val);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int max_val = INT_MAX; int i=0;
        return rec(preorder,i,max_val);
    }
};


O(3N)   because we traversing a node 3 times


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
