// Maximum Depth of Binary Tree

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return 1+max(lh,rh);
    }
};


class Solution {
public:
    int maxDepth(TreeNode *root){
        if(root == NULL)
            return 0;

        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;++i)
            {
                TreeNode *p = q.front();
                q.pop();

                if(p->left != NULL)
                    q.push(p->left);
                if(p->right != NULL)
                    q.push(p->right);
            }
            ++res;
        }
        return res;
    }
};



// Diameter of Binary Tree.cc

class Solution {
public:
     int height(TreeNode* root,int &dia){
        if(!root) return 0;
        int lh = height(root->left,dia);
        int rh = height(root->right,dia);
        
        dia = max((lh + rh),dia);
        
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
       height(root,dia);
       return dia;
    }
};
