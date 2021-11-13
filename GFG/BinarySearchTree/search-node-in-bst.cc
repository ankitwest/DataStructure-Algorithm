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
class Solution
{
public:
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
};

// Delete a node in BST
class Solution{
public:
    Node* inorderSucc(Node* curr){
        curr=curr->right;
        while(curr->left)
            curr=curr->left;
        return curr;
    }
    Node *deleteNode(Node *root, int X){
        if(!root) return NULL;
        if(X==root->data){
            if(!root->left and !root->right) 
                return NULL;
            else if(root->left and root->right){
                Node* temp = inorderSucc(root);
                swap(root->data,temp->data);
                root->right = deleteNode(root->right,temp->data);
            }else if(root->left){
                return root->left;
            }else if(root->right){
                return root->right;
            }
        }
        else if(X>root->data) 
            root->right = deleteNode(root->right,X);
        else if(X<root->data)
            root->left  = deleteNode(root->left,X);

        return root;
    }
};
