//Aditya Verma
class Solution {
    int height(Node* root,int &dia){
        if(!root) return 0;
        int lh = height(root->left,dia);
        int rh = height(root->right,dia);
        
        int temp = 1 + max(lh, rh);
        int ans = max(temp, 1 + lh + rh);
        dia = max(dia, ans);
        
        return 1+max(lh,rh);
    }
public:
    int diameter(Node* root) {
       int dia = 0;
       height(root,dia);
       return dia;
    }
};



// Path Sum
//from any node to any node

int findPathSum(TreeNode<int> *root,int &ans){
    if(!root) return 0;
    
    int ls = max(0,findPathSum(root->left,ans));
    int rs = max(0,findPathSum(root->right,ans));
    
    ans = max(ans, ls + rs + root->data);
    
    return max(ls,rs) + root->data;
}

int findPathSum2(TreeNode<int> *root,int &ans){
    if(!root) return 0;
    
    int ls = findPathSum2(root->left,ans);
    int rs = findPathSum2(root->right,ans);
    
    int temp = max(max(ls,rs) + root->data, root->data);
    int res = max(temp, ls + rs + root->data);
    ans = max(ans, res);

    return temp;
}
int maxPathSum(TreeNode<int> *root)
{
   int ans = -1e9;
    findPathSum2(root,ans);
    return ans;

}
