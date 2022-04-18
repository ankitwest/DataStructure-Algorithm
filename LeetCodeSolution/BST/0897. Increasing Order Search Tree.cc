


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
    void solve(TreeNode* root,TreeNode* &ans){
        if(!root) return ;
        
        solve(root->left,ans);
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        solve(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* ans = new TreeNode(0);
        TreeNode* temp = ans;
        
        solve(root,ans);
        return temp->right;
    }
};



//Behera
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root==nullptr) return nullptr;
        
        multiset<int> se;
        
        auto recur = [&se](TreeNode* node, const auto& recur){
            if(node==nullptr) return;
            
            se.insert(node->val);
            
            recur(node->left, recur);
            recur(node->right, recur);
        };
        
        recur(root, recur);
        
        auto it = se.find(*se.begin());
        
        TreeNode* newRoot = new TreeNode(*it);
        
        TreeNode* tempNode = newRoot;

        se.erase(it);

        while(!se.empty()){
            it = se.find(*se.begin());
        
            tempNode->right = new TreeNode(*it);
        
            tempNode = tempNode->right;
            
            se.erase(it);
        }
        
        return newRoot;
    }
};
