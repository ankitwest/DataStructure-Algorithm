
class Solution{
  public:
    void inorder_tree(Node* root,vector<int> &nums){
        if(!root) return ;
        
        inorder_tree(root->left,nums);
        nums.push_back(root->data);
        inorder_tree(root->right,nums);
    }

    Node* build(vector<int> &nums,int l,int r){
        if(l>r)
            return NULL;
        
        int mid = l + (r-l)/2;
        int val = nums[mid];
        Node* root = new Node(val);
        
        root->left = build(nums, l, mid-1);
        root->right = build(nums, mid+1, r);
         
        return root;
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> nums;
       inorder_tree(root,nums);
       int n = nums.size();
       
       sort(nums.begin(),nums.end());
       
       return build(nums,0,n-1);
    }
};
