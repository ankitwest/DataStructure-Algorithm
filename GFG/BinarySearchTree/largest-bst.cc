struct Bst{
    bool isBst;
    int size;
    int min;
    int max;
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Bst largestBstFun(Node* root){
        if(!root) {
            Bst b = {true,0,INT_MAX,INT_MIN};
            return b;
        }
        Bst l=largestBstFun(root->left);
        Bst r=largestBstFun(root->right);
        
        if(l.isBst and r.isBst and l.max<root->data and r.min>root->data){
            Bst b = {true, 1+l.size+r.size , min(l.min,root->data) , max(r.max,root->data)};
            return b;
        }
        Bst b = {false,max(l.size,r.size),-1,-1};
        return b;
    }
    int largestBst(Node *root)
    {
        Bst b =largestBstFun(root);
        return b.size;
    }
};
Expected Time Complexity: O(N).
