class Solution{
public:
    void helper(Node* root,int val,int level,pair<Node*,int> &p){
        if(!root) return ;
        if(root->left){
                if(root->left->data==val) p = {root,level};
        }
        if(root->right){
               if(root->right->data==val) p = {root,level};
        }


        helper(root->left,val,level+1,p);
        helper(root->right,val,level+1,p);
    }
    bool isCousins(Node *root, int a, int b)
    {
        pair<Node*,int>a1;
        pair<Node*,int>b1;

        helper(root,a,1,a1);
        helper(root,b,1,b1);

        if(a1.first!=b1.first and a1.second==b1.second) return 1;
        return 0;
    }
};

       1
     /   \ 
    2     3
   /       \
  5         4 
a = 5, b = 4
Output: 1
