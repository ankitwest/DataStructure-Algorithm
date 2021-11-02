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
