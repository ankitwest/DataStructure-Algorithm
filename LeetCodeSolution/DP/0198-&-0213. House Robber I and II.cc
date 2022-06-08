class Solution {
public:
    int robber(vector<int> &nums){
        int n = nums.size();
        int dp[n];
        fill(dp,dp+n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1] , nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        vector<int> v(nums.begin(),nums.end());
        
        return robber(v);
    }
};



class Solution {
public:
    int robber(vector<int> &nums){
        int n = nums.size();
        int dp[n]; fill(dp,dp+n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1] , nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max({nums[0],nums[1],nums[2]});
        
        vector<int> v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin()+1,nums.end());
        
        return max(robber(v1),robber(v2));
    }
};




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
public:  //  TC- O(N)   SC - O(N)
    unordered_map<TreeNode*,int>m;
    int solve(TreeNode* root){
        if(!root) return NULL;
        
        if(m.find(root)!=m.end())
            return m[root];
        
        int robRoot = root->val;
        if(root->left)
            robRoot += solve(root->left->left) + solve(root->left->right);
        if(root->right)
            robRoot += solve(root->right->left) + solve(root->right->right);
        
        int notRobRoot = solve(root->left) + solve(root->right);
        
        return m[root] = max(robRoot,notRobRoot);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};


//pair wala without space
class Solution2 {
    struct RobbedRoot {
        int robbedRoot;
        int skippedRoot;
    };
public:
    RobbedRoot robDFS(TreeNode* root) {
        if (!root) {
            return RobbedRoot{0, 0};
        }
        
        RobbedRoot robLeft = robDFS(root->left);
        RobbedRoot robRight = robDFS(root->right);
        
        int robThisNode = root->val + robLeft.skippedRoot + robRight.skippedRoot;
        int skipThisNode = max(robLeft.robbedRoot, robLeft.skippedRoot) +                                                max(robRight.robbedRoot, robRight.skippedRoot);
        
        return RobbedRoot{robThisNode, skipThisNode};
    }
    int rob(TreeNode* root) {
        RobbedRoot finalState = robDFS(root);
        
        return max(finalState.robbedRoot, finalState.skippedRoot);
    }
};
