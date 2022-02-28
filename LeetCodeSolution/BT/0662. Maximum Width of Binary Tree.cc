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
        int width = 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            int max_index = INT_MIN; int min_index = INT_MAX;
            while(n--){
                auto curr = q.front(); q.pop();
                TreeNode* tmp = curr.first;
                int dist = curr.second;
                max_index = max(max_index, dist);
                min_index = min(min_index, dist);
                if(tmp->left)
                    q.push({tmp->left,(long long)2*dist+1});
                if(tmp->right)
                    q.push({tmp->right,(long long)2*dist+2});
            }
            width = max(width, max_index - min_index + 1);
        }
        return width;
    }
};


Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
