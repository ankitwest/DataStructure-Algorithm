
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root == p or root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(!left) return right;
        if(!right) return left;
        
        return root;
    }
};

// recursive simple
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if((root->val > p->val) and (root->val > q->val))
            return lowestCommonAncestor(root->left, p, q);
        if((root->val < p->val) and (root->val < q->val))
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};

//iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(true){
            if(curr->val > p->val and curr->val > q->val)
                curr = curr->left;
            else if(curr->val < p->val and curr->val < q->val)
                curr = curr->right;
            else
                break;
        }      
        return curr;
    }
};


// example - 2,6,8  p = 2 q = 8


