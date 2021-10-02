class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int n=v.size();
        int minn=INT_MAX;
        for(int i=0;i<n-1;i++){
            minn = min(minn,abs(v[i]-v[i+1]));
        }
        return minn;
    }
};
