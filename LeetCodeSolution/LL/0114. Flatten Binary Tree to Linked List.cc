

//Morris Traversal
class Solution {
public:     //  O(1) space
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right)
                    prev = prev->right;
                
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

// if u want to reach at the last node use while(curr->next)


class Solution2 {
public:       // recursion
    void flatten(TreeNode* root) {
        if(!root or (!root->left and !root->right))  return;
        
        if(root->left){
            flatten(root->left);
            TreeNode* tempRight = root->right;
            
            root->right = root->left;
            root->left = NULL;
            
            auto t = root->right;
            while(t->right) 
                t = t->right;
            
            t->right = tempRight;
        }
        flatten(root->right);
    }
};

[1,3,4,null,null,2,null,null,5]
[]
[0]
[1,2]
sol
[1,null,3,null,4,null,2,null,5]
[]
[0]
[1,null,2]
