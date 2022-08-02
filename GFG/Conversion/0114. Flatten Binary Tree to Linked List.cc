// Note:
// if u want to reach at the last node use while(curr->next)

GFG  
https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

// Morris Traversal 
// TC -  O(N) SC - O(1) space
// Iterative preorder
class Solution {
public:     
    void flatten(TreeNode* root) {
        // TreeNode* curr = root;
        while(root)
        {
            if(root->left)  // if it exists
            {
                TreeNode* last = root->left;   //last guy of left subtree
                while(last->right)
                    last = last->right;
                
                last->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};


// recusion
// reverse postorder
// TC - O(N)  SC - O(N)
class Solution2 {
    TreeNode *prev = NULL;
public:   
     void flatten(TreeNode *root) {
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};


// TC - O(N)  SC - O(N)
class Solution4 {
public:       
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()){
            TreeNode *curr = st.top(); st.pop();
            
            if(curr->right)  
                st.push(curr->right);
            if(curr->left)   
                st.push(curr->left);
            
            if(!st.empty()) 
                 curr->right = st.top(); // make the right top
             
            curr->left = NULL;       // dont forget this!! 
        }
    }
};


