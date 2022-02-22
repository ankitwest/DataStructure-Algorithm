


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
    // -1 need cover  
    //  0 already covered
    // 1 camera at this node
    int ans=0;
    int solve(TreeNode* root){
        if(!root)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left==-1 or right==-1){
            ans++;
            return 1;
        }
        else if(left==1 or right==1){
            return 0;
        }
        else // if(left==0 or right==0)
            return -1;
    }
    int minCameraCover(TreeNode* root) {
        
        if(solve(root)==-1)
            ans++;
        return ans;
    }
};


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
