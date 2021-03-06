//bfs
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            auto left = curr->left;
            auto right = curr->right;
            curr->left = right;
            curr->right = left;
            
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return root;
    }
};


//recursion
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if(!root) return NULL;
      
      invertTree(root->left);
      invertTree(root->right);
      swap(root->left, root->right);
      
      return root;
    }
};
