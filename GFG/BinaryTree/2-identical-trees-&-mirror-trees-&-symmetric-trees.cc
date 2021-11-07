
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

// Check for Subtree
class Solution
{
  public:
    bool identical(Node* r1,Node* r2){
        if(!r1 and !r2) return true;
        if(!r1 or !r2) return false;
        
        if(r1->data!=r2->data) return false;
        return (r1->data==r2->data) and identical(r1->left,r2->left) and identical(r1->right,r2->right);
    }
    bool isSubTree(Node* T, Node* S) 
    {
       queue<Node*> q;
       q.push(T);
       while(!q.empty()){
           auto curr = q.front();q.pop();
           if(curr->data==S->data) {
               if(identical(curr,S))
                return true;
           }
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
       return false;
    }
};
Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 


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
