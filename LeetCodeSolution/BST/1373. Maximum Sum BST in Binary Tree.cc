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
class Bst{
public:
    bool isBst;
    int sum;
    int min;
    int max;
    Bst(bool isBst,int sum,int min,int max){
        this->isBst = isBst;
        this->sum = sum;
        this->min = min;
        this->max = max;
    }
};
class Solution {
    int ans = 0;
    Bst findMaxBST(TreeNode* root){
        if(!root)
            return Bst(true,0,INT_MAX,INT_MIN);
    
        Bst l = findMaxBST(root->left);
        Bst r = findMaxBST(root->right);
        
        if(l.isBst and r.isBst and root->val>l.max and root->val<r.min){
            ans = max(ans,l.sum + r.sum + root->val);
            return {true, l.sum + r.sum + root->val, min(l.min, root->val), max(r.max, root->val)};
        }

        return {false, max(l.sum, r.sum), INT_MIN, INT_MAX};  //MAX MIN  both 
    }
public:
    int maxSumBST(TreeNode* root) {
        findMaxBST(root);
        return ans;
    }
};


Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
