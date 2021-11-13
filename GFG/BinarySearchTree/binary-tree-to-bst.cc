class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder_tree(Node* root,vector<int> &v){
        if(!root) return ;
        
        inorder_tree(root->left,v);
        v.push_back(root->data);
        inorder_tree(root->right,v);
    }
    void inorder_bst(Node* root,vector<int> &v,int &i){
        if(!root) return ;
        inorder_bst(root->left,v,i);
        root->data=v[i++];
        inorder_bst(root->right,v,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> v;
       inorder_tree(root,v);
       sort(v.begin(),v.end());
       int i=0;
       inorder_bst(root,v,i);
       return root;
       
    }
};
Expected Time Complexity: O(NLogN).
