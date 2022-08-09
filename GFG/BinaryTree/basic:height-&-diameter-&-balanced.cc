// Q
//Height
class Solution{
    public:
    int height(struct Node* root){
       if(!root) return 0;
        
       int lh = height(root->left);
       int rh = height(root->right);
        
       return  1 + max(lh,rh);
    }
};
Expected Time Complexity: O(N)

    
    
    
    // Q
    //Diameter
    
    
class Solution {
  public:
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


//Q
// Is tree balanced

class Solution{
    public:
    int height(Node* root,bool &flag){
        if(!root) return 0;
        
        int lh = height(root->left,flag);
        int rh = height(root->right,flag);
        
        if(abs(lh-rh)>1) 
            flag=false;
        
        return 1+max(lh,rh);
    }
    bool isBalanced(Node *root)
    {
        bool flag=true;
      height(root,flag);
       return flag;
       
    }
};
// without global variable
class Solution {
    int height(TreeNode* root){
        if(!root) return 0;
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        if(lh==-1 or rh==-1 or abs(lh-rh)>1) return -1;
        
        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h = height(root);
        return h == -1 ? 0 : 1;
    } 
};

Expected time complexity: O(N)


