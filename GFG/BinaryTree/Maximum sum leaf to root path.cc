class Solution{
  // int ans = INT_MIN;
    int solve(Node* root){
        if(!root) return 0;
        
        if(!root->left and !root->right) return root->data;
        
        int leftS = solve(root->left);
        int rightS = solve(root->right);
        
        // ans = max(ans,max(leftS,rightS) + root->data ) ;
        return max(leftS,rightS) + root->data;
    }
    public:
    int maxPathSum(Node* root)
    {
        return solve(root);
    }
};
