class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> store(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();q.pop();
                int index = leftToRight ? i : size-i-1;
                store[index] = node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(store);
        }
        return ans;
    }
};
oot = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
