class Solution{
  public:
  Node* LCA(Node *root, int n1, int n2)
 {
   if(!root) return NULL;
   
    if(root->data>n1 and root->data>n2)
    return LCA(root->left,n1,n2);
    if(root->data<n1 and root->data<n2)
    return LCA(root->right,n1,n2);
    if((root->data>n1 and root->data<n2) or (root->data<n2 and root->data<n1))
        return root;
        
    return root;
}
};
Expected Time Complexity: O(Height of the BST).
