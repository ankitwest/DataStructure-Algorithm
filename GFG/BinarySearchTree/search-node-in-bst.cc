//Search node in BST
class Solution
{
public:
bool search(Node* root, int x) {
    if(!root) return 0;
    
    if(root->data==x) return 1;
    else if(root->data>x) return search(root->left,x);
    else if(root->data<x) return search(root->right,x);
   
    return false;
}
};

// Find Min and Max
class Solution
{
public:
    int findMax(Node *root)
    {
        while(root->right)
            root=root->right; 
            
        return root->data;
    }
    int findMin(Node *root)
    {
        while(root->left)
            root=root->left;
            
        return root->data;
    }
};

// Insert a node in BST
Node* insert(Node* root, int Key) {
    if(!root) {
        Node* root = new Node(Key);
        return root;
    }
    if(Key==root->data) 
         return root;
    if(Key>root->data) 
        root->right = insert(root->right,Key);
    if(Key<root->data) 
        root->left = insert(root->left,Key);
    
    return root;
    
}
