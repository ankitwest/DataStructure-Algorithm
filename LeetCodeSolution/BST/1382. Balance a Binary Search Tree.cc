/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) 
            return NULL;
        
        vector<int> v;
        auto inorder = [&v](auto inorder,TreeNode* root) ->void{
            if(!root) return ;
            
            inorder(inorder,root->left);
            v.push_back(root->val);
            inorder(inorder,root->right);
        };
        inorder(inorder,root);
        
        auto buildTree = [&v](auto buildTree,int s,int e) ->TreeNode*{
            if(s>e)
                return NULL;
            if(s==e)
                return new TreeNode(v[s]);
            
            int mid = (s+e)/2;
            TreeNode* root = new TreeNode(v[mid]);
            root->left = buildTree(buildTree,s,mid-1);
            root->right = buildTree(buildTree,mid+1,e);
            
            return root;
        };
        return buildTree(buildTree,0,v.size()-1);
    }
};


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
