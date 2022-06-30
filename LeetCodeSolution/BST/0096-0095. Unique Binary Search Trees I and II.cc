
class Solution1 {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1; 
        dp[1] = 1;
        for(int k=2;k<=n;k++){
            int sum = 0;
            for(int i=1;i<=k;i++){
                sum += dp[i-1] * dp[k-i];  // F(i-n) = 
            }
            dp[k] = sum;
        }
        return dp[n];
    }
};


class Solution {
    vector<vector<int>> dp;
    int solve(int start,int end){
        if(start>end)
            return 0;
        if(start==end)
            return 1;
        
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        int ans = 0;
        for(int i=start;i<=end;i++){
            int left = solve(start,i-1);
            int right = solve(i+1,end);
            
            left = (left > 0) ? left : 1;
            right = (right > 0) ? right : 1;
            
            ans += left * right;
        }
        return dp[start][end] = ans;
    }
public:
    int numTrees(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(1,n);
    }
};

/*
https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
*/





0095. Unique Binary Search Trees II

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
    vector<TreeNode*> rec(int start,int end){
        vector<TreeNode*> ans;
        
        if(start>end){
            ans.push_back({NULL});
            return ans;
        }

        
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = rec(start,i-1);
            vector<TreeNode*> right = rec(i+1,end);
            
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return rec(1,n);
    }
};


/*
 https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/1440190/C%2B%2B-Python-Simple-and-Short-Recursive-Solutions-With-Explanation
*/

