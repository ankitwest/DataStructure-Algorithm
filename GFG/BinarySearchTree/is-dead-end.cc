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
