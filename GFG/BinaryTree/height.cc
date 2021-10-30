class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
       if(!root) return 0;
       return  1 + max(height(root->left),height(root->right));
    }
};



class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
       if(!root) return 0;
       if(!root->left and !root->right) return 1;
       
       return  1 + max(height(root->left),height(root->right));
    }
};


Expected Time Complexity: O(N)
