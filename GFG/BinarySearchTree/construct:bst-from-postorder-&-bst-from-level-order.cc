class Solution{
  public:
  Node* construct(int arr[],int s,int e){
    if(s>e) return NULL;
    int mid = (s+e)/2;
    Node* root = new Node(arr[mid]);
    root->left = construct(arr,s,mid-1);
    root->right = construct(arr,mid+1,e);
    
    return root;
}
Node *constructTree (int post[], int n)
{
sort(post,post+n);
return construct(post,0,n-1);
}
};

Expected Time Complexity: O(Height of the BST)

  
  // Construct BST from level order traversal 
//   and return preorder of BST
  class Solution{
    public:
      Node* construct(vector<int> v){
      if(v.size()==0) return NULL;
      Node* root = new Node(v[0]);
      vector<int> l,r;
      for(int i=1;i<v.size();i++){
          if(v[i]<v[0]) l.push_back(v[i]);
          else r.push_back(v[i]);
      }
      root->left = construct(l);
      root->right = construct(r);

      return root;
  }
  Node* constructBst(int arr[], int n)
  {
      vector<int> a(arr,arr+n);
      return construct(a);
  }
 };
Expected Time Complexity: O(N)

