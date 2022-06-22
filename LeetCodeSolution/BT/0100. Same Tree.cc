//  Level Order Traversal
//  Time Complexity - O(N)
//  Space Complexity - O(N)
class Solution {
   public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<pair<TreeNode *,TreeNode *>> que;
        que.push({p, q});
        while (!que.empty()) {
            TreeNode *node1 = que.front().first;
            TreeNode *node2 = que.front().second;
            que.pop();
            if (!node1 and !node2) continue;
            if (!node1 or !node2) return false;
            if (node1->val != node2->val) return false;
            que.push({node1->left, node2->left});
            que.push({node1->right, node2->right});
        }
        return true;
    }
};

class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        if(!p or !q) return false;
        
        return (p->val==q->val) and isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
};
