  //Function to convert binary tree to doubly linked list and return it.
class Solution{
   public: 
    void conversion(Node* root,Node* &head,Node* &prev){
        if(!root) return ;
        conversion(root->left,head,prev);
        if(!head){
            head = root;
            prev = root;
        }else{
            root->left = prev;
            prev->right = root;
            prev = root;
        }
        conversion(root->right,head,prev);
        return ;
    }
    Node * bToDLL(Node *root)
    {
       Node* head=NULL;
       Node* prev=NULL;
       conversion(root,head,prev);
      return head;
    }
  ];
  Expected Time Complexity: O(N).

     
     
     // return the head of the DLL and remove those node from the tree as well.
class Solution{
   public:     
     Node* convert(Node* root,Node* &head,Node* &prev){
    if(!root) return NULL;
    if(!root->left and !root->right){
        if(!head){
            head=root;
            prev=root;
        }else{
            root->left=prev;
            prev->right=root;
            prev=root;
        }
        return NULL;
    }
    root->left=convert(root->left,head,prev);
    root->right=convert(root->right,head,prev);
    
    return root;
}
Node * convertToDLL(Node *root){
    Node* head=NULL;
    Node* prev=NULL;
    convert(root,head,prev);
    return head;
}
};
