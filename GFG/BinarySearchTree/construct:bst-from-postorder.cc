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
