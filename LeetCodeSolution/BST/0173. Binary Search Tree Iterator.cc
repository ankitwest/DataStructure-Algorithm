class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    int next() {
        TreeNode* top = st.top();
        st.pop();
        partialInorder(top->right);
        return top->val;
    }
    bool hasNext() {
        return !st.empty();
    }
private:
    void partialInorder(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};
