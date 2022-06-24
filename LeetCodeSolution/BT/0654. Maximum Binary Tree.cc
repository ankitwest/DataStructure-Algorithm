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
private:    
    TreeNode* solve(vector<int>& nums,int left,int right){
        if(left>right) return NULL;
        
        int max_index = left;
        for(int i = left; i<=right; i++){
            if(nums[i] > nums[max_index])
                max_index = i; 
        }
        
        TreeNode* root = new TreeNode(nums[max_index]);
        root->left = solve(nums,left,max_index-1);
        root->right = solve(nums,max_index+1,right);
            
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};


//using stack
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         stack<TreeNode*> st;
//         for (int num : nums) {
//             TreeNode* node = new TreeNode(num);
//             while (!st.empty() and st.top()->val < node->val) {
//                 node->left = st.top();
//                 st.pop();
//             }
//             if (!st.empty())  st.top()->right = node;
            
//             st.push(node);
//         }
        
//         while (st.size()>1)
//             st.pop();
    
//         return st.top();
//     }
// };
