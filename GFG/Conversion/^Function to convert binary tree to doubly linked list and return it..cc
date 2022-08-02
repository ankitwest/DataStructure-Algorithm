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
