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
        
       int lh = height(root->left);
       int rh = height(root->right);
        
       return  1 + max(lh,rh);
    }
};


Expected Time Complexity: O(N)
