
// Note:
// if u want to reach at the last node use while(curr->next)

//Morris Traversal
// TC - Iterative O(N)
// SC - O(1) space
// preorder
class Solution {
public:     
    void flatten(TreeNode* root) {
        // TreeNode* curr = root;
        
        while(root)
        {
            if(root->left)
            {
                TreeNode* last = root->left;   //last guy of left subtree
                while(last->right)
                    last = last->right;
                
                last->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};

// TC - O(N)  SC - O(N)
class Solution2 {
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
                 curr->right = st.top();
            curr->left = NULL;       // dont forget this!! 
        }
    }
};


// class Solution2 {
// public:       // recursion
//     void flatten(TreeNode* root) {
//         if(!root or (!root->left and !root->right))  return;
        
//         if(root->left){
//             flatten(root->left);
//             TreeNode* tempRight = root->right;
            
//             root->right = root->left;
//             root->left = NULL;
            
//             auto t = root->right;
//             while(t->right) 
//                 t = t->right;
            
//             t->right = tempRight;
//         }
//         flatten(root->right);
//     }
// };




//rahul
//recusion
// reverse postorder
// TC - O(N)  SC - O(N)
class Solution3 {
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




[1,3,4,null,null,2,null,null,5]
[]
[0]
[1,2]
sol
[1,null,3,null,4,null,2,null,5]
[]
[0]
[1,null,2]
