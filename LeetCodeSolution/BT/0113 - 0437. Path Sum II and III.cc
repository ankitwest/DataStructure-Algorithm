class Solution {
    vector<vector<int>> ans;
    void solve(TreeNode* root,int sum,vector<int> &v){
        if(!root) return;
        
        if(!root->left and !root->right and sum==root->val){
            v.push_back(root->val);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        
        v.push_back(root->val);
        solve(root->left,sum-root->val,v);
        solve(root->right,sum-root->val,v);
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        vector<int> v;
        
        solve(root,targetSum,v);
        return ans;
    }
};




class Solution {
    int cnt = 0;
    void solve(TreeNode* root,long long sum){
        if(!root) return;
        
        if(sum==root->val){
            cnt++;
            // return;  keep ongoing the search
        }
        
        solve(root->left,sum-root->val);
        solve(root->right,sum-root->val);
    }
public:
    int pathSum(TreeNode* root,int targetSum) {
        if(!root) return 0;
        
        solve(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return cnt;
    }
};
