struct Bst{
    bool isBst;
    int size;
    int min;
    int max;
};
class Solution{
    public:
    Bst largestBstFun(Node *root){
        if(!root)
            return {true,0,INT_MAX,INT_MIN};
        
        Bst l = largestBstFun(root->left);
        Bst r = largestBstFun(root->right);
        
        if(l.isBst and r.isBst and root->data > l.max and root->data < r.min){
            return {true,l.size + r.size + 1, min(l.min,root->data), max(root->data,r.max)};
        }
        
        return {false,max(l.size,r.size),-1,-1};  // min,max;
    }
    int largestBst(Node *root)
    {
        return largestBstFun(root).size;
    }
};



// TC - O(N) postorder 
// SC - O(1) 


 //postorder call because will have to check left -> right and then at last root
class Bst{
public:    
    bool isBst;
    int size;
    int min;
    int max;
    Bst(bool isBst,int size,int min,int max){
        this->isBst = isBst;
        this->size = size;
        this->min = min;    
        this->max = max;
        
    }
};
class Solution{
    public:
   
    Bst largestBstFun(Node *root){
        if(!root) {
            return Bst(true,0,INT_MAX,INT_MIN);
        }
        Bst l=largestBstFun(root->left);
        Bst r=largestBstFun(root->right);
        
        if(l.isBst and r.isBst and l.max<root->data and root->data<r.min){
            return Bst(true, 1+l.size+r.size , min(l.min,root->data) , max(r.max,root->data));
     
        }
        return Bst(false,max(l.size,r.size),-1,-1);  //min,max
    }
    int largestBst(Node *root)
    {
        return largestBstFun(root).size;
    }
};
Expected Time Complexity: O(N).
