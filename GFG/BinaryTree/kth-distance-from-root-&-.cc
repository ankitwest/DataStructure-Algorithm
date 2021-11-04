class Solution{
  public:
  void helper(Node* root,int k, vector<int> &v){
    if(!root) return ;
        
    helper(root->left,k-1,v);
    helper(root->right,k-1,v);
    if(k==0)
      v.push_back(root->data);
    
}
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> v;
  helper(root,k,v);
  return v;
}
};
Expected Time Complexity: O(N).
