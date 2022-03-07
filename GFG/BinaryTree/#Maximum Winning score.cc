class Solution{
public:
    //Function to return maximum path product from any node in a tree.
    long long maxi = 0;
    void pro(Node* root,long long &ans){
        if(!root) return ;
        
        long long l=1,r=1;
        if(root->left){
            l = ans*(root->left->data);
            pro(root->left,l);
        }
        if(root->right){
            r = ans*(root->right->data);
            pro(root->right,r);
        }
        
        maxi = max({maxi,l,r});
    }
    long long findMaxScore(Node* root)
    {
        if(!root) return 0;
        if(root and !root->left and !root->right) return root->data;
        
        long long ans=root->data;
        pro(root,ans);
        return maxi;
    }
};


//
Input:
     10
   /    \
  7      5
          \
           1
Output: 70
Explanation: The path 10, 7 gives a 
score of 70 which is the maximum possible.
