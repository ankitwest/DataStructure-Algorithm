// Check for BST
// Using Range

class Solution{
  public:
    //Function to check whether a Binary Tree is BST or not.
    void checkBST(Node* root,int l,int r,bool &flag){
        if(!root) return ;
        if(l>root->data or r<root->data)
            {flag =0; return ;}
           
        checkBST(root->left,l,root->data-1,flag);
        checkBST(root->right,root->data+1,r,flag);
    }
    bool isBST(Node* root) 
    {
      bool flag=-1;
       checkBST(root,1,INT_MAX,flag);
       return flag;
    }
};



// Check for Dead End
// Using Range

class Solution{
  public:
  void deadEnd(Node* root,int l,int r,bool &flag){
    if(!root) return ;
    if(flag) return ;
    
    if(!root->left and !root->right and l==r){
        flag=1;return;
    }
    deadEnd(root->left,l,root->data-1,flag);
    deadEnd(root->right,root->data+1,r,flag);
    
}
bool isDeadEnd(Node *root)
{
    bool flag = 0;
    deadEnd(root,1,INT_MAX,flag);
    return flag;
}
};
