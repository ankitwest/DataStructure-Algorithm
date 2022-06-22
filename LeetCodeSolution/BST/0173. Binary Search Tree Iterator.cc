class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        leftInorder(root);
    }
    int next() {
        TreeNode* top = st.top();
        st.pop();
        leftInorder(top->right);
        return top->val;
    }
    bool hasNext() {
        return !st.empty();
    }
private:
    void leftInorder(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};

