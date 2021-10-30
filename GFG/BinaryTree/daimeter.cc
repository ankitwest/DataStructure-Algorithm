class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
    private:
    int height(TreeNode* node,int &diameter){
        if(node==NULL) return 0;
        int lh = height(node->left,diameter);  //for every node lh+rh
        int rh = height(node->right,diameter);
        
        diameter = max(lh+rh , diameter);  //comparing with previous max
        
        return 1+max(lh,rh);   //returning +1;
        
    }
};





class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int h=0;
        diameter(root,h);
        return h;
    }
    int diameter(TreeNode* root,int &h){
        if(root==NULL){
            h=0;
            return 0;
        }
        
        int lh=0,rh=0;
        int lDiameter=diameter(root->left,lh);
        int rDiameter=diameter(root->right,rh);

        h = max(lh,rh)+ 1;

     return max({lh+rh ,lDiameter ,rDiameter });

        
    }
};
