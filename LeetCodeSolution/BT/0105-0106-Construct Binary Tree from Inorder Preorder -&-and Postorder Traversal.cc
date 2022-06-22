
//  105. Construct Binary Tree from Preorder and Inorder Traversal
class Solution1 {
    unordered_map<int,int>m;
    TreeNode* construct(int &start,vector<int>& preorder, vector<int>& inorder,int inS,int inE){
        if(inS > inE) return NULL;
        
        int rootVal = preorder[start++];
        TreeNode* root = new TreeNode(rootVal);
        if(inS == inE) return root;
        
        int mid = m[rootVal];
        
        root->left = construct(start,preorder,inorder,inS,mid-1);
        root->right = construct(start,preorder,inorder,mid+1,inE);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // m.clear();
        int n = inorder.size();
        for(int i=0;i<n;i++) m[inorder[i]] = i;
        
        int start = 0;
        return construct(start,preorder,inorder,0,n-1);
    }
};







 // 106. Construct Binary Tree from Inorder and Postorder Traversal
class Solution {
    unordered_map<int,int>m;
    TreeNode* construct(int &end,vector<int>& preorder, vector<int>& inorder,int inS,int inE){
        if(inS > inE) return NULL;
        
        int rootVal = preorder[end--];
        TreeNode* root = new TreeNode(rootVal);
        if(inS == inE) return root;
        
        int mid = m[rootVal];
        
        root->right = construct(end,preorder,inorder,mid+1,inE);
        root->left = construct(end,preorder,inorder,inS,mid-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++) m[inorder[i]] = i;
        
        int end = n-1;
        return construct(end,postorder,inorder,0,n-1);
    }
};
