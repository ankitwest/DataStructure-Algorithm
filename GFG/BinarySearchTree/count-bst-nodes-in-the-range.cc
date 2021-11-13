class Soluiton{
public:
  void inorder(Node* root,vector<int> &v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
int getCount(Node *root, int l, int h)
{
    if(!root) return 0;
  vector<int> v;
  inorder(root,v);
  auto lb = lower_bound(v.begin(),v.end(),l);
   auto ub = upper_bound(v.begin(),v.end(),h);
   return ub-lb;
}
};
Expected Time Complexity: O(N)

  
  
  // M-2
class Soluiton{
public:
  int getCount(Node *root, int l, int h)
{
    if(!root) return 0;
       
    if(l>root->data)
        return getCount(root->right,l,h);
    else if(root->data>h)
        return getCount(root->left,l,h);
    
    return 1+getCount(root->left,l,h)+getCount(root->right,l,h);
}
};
