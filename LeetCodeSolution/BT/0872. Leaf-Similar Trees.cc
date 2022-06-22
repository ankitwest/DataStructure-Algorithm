class Solution {
    void dfs(TreeNode* root,vector<int> &v){
        if(!root) return;
        
        dfs(root->left,v);
        dfs(root->right,v);
        
        if(!root->left and !root->right) v.push_back(root->val);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        dfs(root1,v1);
        dfs(root2,v2);
        
        return v1==v2;
    }
};

class Solution {
    int dfs(stack<TreeNode*> &st){
         while (true) {
            TreeNode* node = st.top(); st.pop();
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
            if (!node->left and !node->right) return node->val;
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       stack<TreeNode*> st1,st2;
        st1.push(root1); st2.push(root2);
        while(!st1.empty() and !st2.empty()){
            if(dfs(st1) != dfs(st2)) return false;
        }
        if(!st1.empty() or !st2.empty()) return false;
        return true;
    }
};

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
