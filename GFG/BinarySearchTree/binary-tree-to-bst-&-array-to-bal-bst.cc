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
  
  
  
  // Array to Balanced BST  
  // return its preorder
  class Soluiton{
    public:
    void build_BST(vector<int> &nums,vector<int> &v, int s,int e){
        if(s<=e){
            int mid = (s+e)/2;
            v.push_back(nums[mid]);
            build_BST(nums,v,s,mid-1);
            build_BST(nums,v,mid+1,e);
        }
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
       vector<int> v;
       int s=0,e=nums.size()-1;
       build_BST(nums,v,s,e);
       return v;
    }
  };
Input: nums = {1,2,3,4,5,6,7}
Ouput: {4,2,1,3,6,5,7}
The preorder traversal of the following
BST formed is {4,2,1,3,6,5,7} 
