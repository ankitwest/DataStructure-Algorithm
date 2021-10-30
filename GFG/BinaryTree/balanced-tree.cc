class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
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
    //   cout<<height(root,flag)<<endl;
      height(root,flag);
       return flag;
       
    }
};


Expected time complexity: O(N)
