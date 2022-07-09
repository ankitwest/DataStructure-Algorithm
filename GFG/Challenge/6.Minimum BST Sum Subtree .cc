class Bst{
public:
    bool isBst;
    int sum;
    int size;
    int min;
    int max;
    Bst(bool isBst,int size,int sum,int min,int max){
        this->isBst = isBst;
        this->sum = sum;
        this->size = size;
        this->min = min;
        this->max = max;
    }
};
class Solution {
       int ans = INT_MAX;
       int tar = 0;
    Bst findMaxBST(Node* root){
        if(!root)
            return Bst(true,0,0,INT_MAX,INT_MIN);
    
        Bst l = findMaxBST(root->left);
        Bst r = findMaxBST(root->right);
        
        if(l.isBst and r.isBst and root->data>l.max and root->data<r.min){
            if((l.sum + r.sum + root->data)==tar)
                ans = min(ans,1+l.size+r.size);

            return Bst(true,1+l.size+r.size , l.sum + r.sum + root->data, min(l.min, root->data), max(r.max, root->data));
        }

        return Bst(false,max(l.size,r.size), max(l.sum, r.sum), INT_MIN, INT_MAX);  //MAX MIN  both 
    }
public:
    int minSubtreeSumBST(int target, Node *root) {
        tar = target;
        findMaxBST(root);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
