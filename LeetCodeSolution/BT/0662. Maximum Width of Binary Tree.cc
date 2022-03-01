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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        long ans = 0;
        while(!q.empty()){
            int n = q.size();
            long start = q.front().second;
            long end = q.back().second;
            ans = max(ans,end-start+1);
            for(int i=0;i<n;i++){
                auto p = q.front(); q.pop();
                TreeNode* node = p.first;
                long idx = p.second;
                if(node->left) q.push({node->left,2*idx+1});
                if(node->right) q.push({node->right,2*idx+2});
            }
        }
        return ans;
    }
};


Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
