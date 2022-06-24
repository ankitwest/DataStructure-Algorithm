
class Solution {
    bool solve(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) 
            return true;
        if((minNode and root->val <= minNode->val) or (maxNode and root->val >= maxNode->val))
            return false;
        return solve(root->left, minNode, root) and solve(root->right, root, maxNode);
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, NULL, NULL);
    }
};


class Solution1 {
    bool solve(TreeNode* root,int min,int max){
        if(!root) 
            return true;
        
        if(root->val <= min or root->val >= max) return false;
           
         return solve(root->left,min,root->val) and solve(root->right,root->val,max);
    }
public:
    bool isValidBST(TreeNode* root) {
       return solve(root,INT_MIN,INT_MAX);
    }
};



// using stack general kinf
class Solution44 {
public:
     bool isValidBST(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        while (root != nullptr or !st.empty()) {
            while (root != nullptr) {
               st.push(root);
               root = root->left;
            }
            root = st.top(); st.pop();
            if(pre != nullptr and root->val<=pre->val) return false;
            pre = root;
            root = root->right;
        }
        return true; 
    }
};
