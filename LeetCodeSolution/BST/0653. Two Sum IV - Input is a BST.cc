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
class Solution2 {
    void inorder(TreeNode* root, vector<int> &nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
        
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j] == k) return true;
            else if(nums[i]+nums[j] < k) i++;
            else j--;
        }
        return false;
    }
};



class BSTIterator {
    stack<TreeNode*> st;
    bool forward = false; 
public:
    BSTIterator(TreeNode *root, bool isForward) {
        forward = isForward; 
        leftInorder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = st.top();
        st.pop();
        if(forward) leftInorder(top->right);
        else leftInorder(top->left);
        return top->val;
    }

private:
    void leftInorder(TreeNode *node) {
        while(node) {
             st.push(node);
             if(forward){
                 node = node->left; 
             }else{
                 node = node->right; 
             }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, true); 
        BSTIterator r(root, false); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i+j == k) return true; 
            else if(i+j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
    }
};
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
