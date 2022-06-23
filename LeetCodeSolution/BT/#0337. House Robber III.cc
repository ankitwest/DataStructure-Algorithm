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
public:  //  TC- O(N)   SC - O(N)
    unordered_map<TreeNode*,int>m;
    int solve(TreeNode* root){
        if(!root) return 0;
        
        if(m.find(root)!=m.end())
            return m[root];
        
        int robRoot = root->val;
        if(root->left)
            robRoot += solve(root->left->left) + solve(root->left->right);
        if(root->right)
            robRoot += solve(root->right->left) + solve(root->right->right);
        
        int notRobRoot = solve(root->left) + solve(root->right);
        
        return m[root] = max(robRoot,notRobRoot);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};


// seems hard
class Solution2 {
    struct RobbedRoot {
        int robbedRoot;
        int skippedRoot;
    };
public:
    RobbedRoot robDFS(TreeNode* root) {
        if (!root) {
            return RobbedRoot{0, 0};
        }
        
        RobbedRoot robLeft = robDFS(root->left);
        RobbedRoot robRight = robDFS(root->right);
        
        int robThisNode = root->val + robLeft.skippedRoot + robRight.skippedRoot;
        int skipThisNode = max(robLeft.robbedRoot, robLeft.skippedRoot) +                                                max(robRight.robbedRoot, robRight.skippedRoot);
        
        return RobbedRoot{robThisNode, skipThisNode};
    }
    int rob(TreeNode* root) {
        RobbedRoot finalState = robDFS(root);
        
        return max(finalState.robbedRoot, finalState.skippedRoot);
    }
};
