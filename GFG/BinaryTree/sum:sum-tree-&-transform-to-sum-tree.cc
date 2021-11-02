// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    int sum(Node* root,bool &flag){
         if(!root) return 0;
         if(!root->left and !root->right) return root->data;
        
        int leftSum = sum(root->left,flag);
        int rightSum = sum(root->right,flag);
        
        if(root->data != leftSum + rightSum)  flag = false;
        
         return leftSum + root->data + rightSum;
    }
    bool isSumTree(Node* root)
    {
         if(!root) return 0;
        bool flag = true;
        int x = sum(root,flag);
      
        return flag;
    }
};


class Solution
{
    public:
    int sum(Node* root){
         if(!root) return 0;
 
         return sum(root->left) + root->data + sum(root->right);
    }
    bool isSumTree(Node* root)
    {
         if(!root) return 0;
         if(!root->left and !root->right) return 1;
    
         return root->data == (sum(root->left) + sum(root->right));
    }
};





// Transform to Sum Tree
class Solution {
  public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node* root){
        if(!root) return 0;
         
        int ls = sum(root->left);
        int rs = sum(root->right);
        
        int temp = root->data;
        root->data = ls + rs;
        return ls + temp + rs;
    }
    void toSumTree(Node *root)
    {
        if(!root) return ;
        sum(root);
    }
};
