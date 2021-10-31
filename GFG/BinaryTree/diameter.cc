
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int calDiameter(Node* root,int &dia){
        if(!root) return 0;
        int lh = calDiameter(root->left,dia);
        int rh = calDiameter(root->right,dia);
        
        dia = max((1+ lh + rh),dia);
        
        return 1+max(lh,rh);
    }
    int diameter(Node* root) {
       int dia = 0;
       calDiameter(root,dia);
       return dia;
    }
};







// Leetcode
// Length of the path from 1 extreme node to another extreme node . Here {2,3,4,5} = 3
class Solution {
  private:
    int height(TreeNode* node,int &dia){
        if(node==NULL) return 0;
        int lh = height(node->left,dia);  
        int rh = height(node->right,dia);
        
        dia = max(lh+rh , dia);         // not adding 1 
        
        return 1+max(lh,rh);  
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        height(root,dia);
        return dia;
    }

};

