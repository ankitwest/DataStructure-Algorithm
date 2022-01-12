class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    
    vector<int> inorder(Node* root,vector<int> &v){
        if(root==NULL)
        return v;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
        
        return v;
    }
    vector<int> inOrder(Node* root) {
        vector<int> v;
        
        return inorder(root,v);
    }
};
