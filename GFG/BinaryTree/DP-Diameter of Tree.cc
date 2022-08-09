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
