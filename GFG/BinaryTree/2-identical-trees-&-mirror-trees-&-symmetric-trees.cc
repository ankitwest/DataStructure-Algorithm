
// Identical Trees   
	// Function to check if two trees are identical.
class Solution
{
    public:
    bool isIdentical(Node *r1, Node *r2)
    {
        if(!r1 and !r2) return true;
        if(!r1 or !r2) return false;
        if(r1->data != r2->data) return false;
        
        return (r1->data == r2->data) and isIdentical(r1->left,r2->left) and isIdentical(r1->right,r2->right);

    }
};



// Invert a tree
	// Function to convert a binary tree into its mirror tree.
class Solution {
  public:
    void invert(Node* root) 
    {
        if(!root) return ;
	    
        invert(root->left);
        invert(root->right);
        swap(root->left,root->right);
    }
};

	//Check if two trees are mirror of each other
    bool mirror(Node* root1,Node* root2){
        if(!root1 and !root2) return true;
        if(!root1 or !root2) return false;
        if(root1->data != root2->data) return false;
        
        return mirror(root1->left,root2->right) and mirror(root1->right,root2->left);
    }




// Symmetric Tree
	 // return true/false denoting whether the tree is Symmetric or not
class Solution{
    public:
     bool mirror(Node* root1,Node* root2){
        if(!root1 and !root2) return true;
        if(!root1 or !root2) return false;
        if(root1->data != root2->data) return false;
        
        return mirror(root1->left,root2->right) and mirror(root1->right,root2->left);
    }
    bool isSymmetric(struct Node* root)
    {
	    if(!root) return true;
        
        bool ans = mirror(root->left,root->right);
        return ans;
 
    }
};
