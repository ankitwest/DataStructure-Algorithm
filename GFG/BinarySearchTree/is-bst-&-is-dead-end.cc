// Check for BST
// Using Range

class Solution{
  public:
    //Function to check whether a Binary Tree is BST or not.
     bool flag=-1;
    void checkBST(Node* root,int l,int r){
        if(!root) return ;
        if(l>root->data or r<root->data)
            {flag =0; return ;}
           
        checkBST(root->left,l,root->data-1);
        checkBST(root->right,root->data+1,r);
    }
    bool isBST(Node* root) 
    {
       checkBST(root,1,INT_MAX);
       return flag;
    }
};




class Solution{
  public:
  bool solve(Node* root,int min,int max)
    {
        if(!root) 
            return true;
        
        bool left = solve(root->left,min,root->data-1);
        bool right = solve(root->right,root->data+1,max);
        
        if(root->data < min or root->data > max or left==false or right==false)
            return false;
           
         return  true;
    }
public:
    bool isBST(Node* root) 
    {
       return solve(root,INT_MIN,INT_MAX);
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
