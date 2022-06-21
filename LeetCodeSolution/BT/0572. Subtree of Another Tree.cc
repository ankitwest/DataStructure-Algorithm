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
    bool identical(TreeNode* a, TreeNode* b){
        if(!a and !b) return true;
        if(!a or !b) return false;
        
        if(a->val != b->val) return false;
        
        return (a->val==b->val) and identical(a->left,b->left) and identical(a->right,b->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        
        if(identical(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true


// M-2
class Solution2 {
    bool identical(TreeNode* a, TreeNode* b){
        if(!a and !b) return true;
        if(!a or !b) return false;
        
        if(a->val != b->val) return false;
        
        return (a->val==b->val) and identical(a->left,b->left) and identical(a->right,b->right);
    }
public:
     bool isSubtree(TreeNode* T, TreeNode* S){
       queue<TreeNode*> q;
       q.push(T);
       while(!q.empty()){
           auto curr = q.front();q.pop();
           if(curr->val==S->val) {
               if(identical(curr,S))
                return true;
           }
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
       return false;
    }
};
