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
    int cost(TreeNode* root,int &moves){
        if(!root) return 0;
        if(root and !root->left and !root->right)
		    return root->val-1;
        
        int left = cost(root->left, moves);
        int right = cost(root->right, moves);
        
        moves+=abs(left) + abs(right);   // ans till now, will be the sum of both left and right
        return left+right+(root->val-1);  // how many coins the node will return
    }
    int distributeCoins(TreeNode* root) {
        if(!root) return 0;
        int moves = 0;
        cost(root,moves);
        return moves;
    }
};
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
