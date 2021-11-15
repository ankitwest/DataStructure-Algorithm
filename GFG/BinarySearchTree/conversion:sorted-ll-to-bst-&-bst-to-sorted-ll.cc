//Sorted LL to BST
class Solution{
    public:
    TNode* constructBST(LNode* &head,int n){
        if(n==0) return NULL;
    
        TNode* root=new TNode(0);
        root->left = constructBST(head,n/2);
        root->data = head->data;
        head = head->next;
        root->right = constructBST(head,(n-1)/2);
        
        return root;
    }
    TNode* sortedListToBST(LNode *head) {
        if(!head) return NULL;
        int l=0; LNode *temp = head;
        while(temp){
            temp=temp->next; l++;
        }
        return constructBST(head,l);
    }
};
Expected Time Complexity: O(N), N = number of Nodes


Linked List: 1->2->3->4->5->6->7
        4
      /   \
     2     6
   /  \   / \
  1   3  5   7  
 Hence,   preorder traversal of this 
tree is 4 2 1 3 6 5 7
    
    
    
    
    
    
    
// Flatten a BST to sorted list
 class Solution{
public:
    void inorder(Node* root,Node* &prev){
    if(!root) return ;

    inorder(root->left,prev);
    prev->left=NULL;
    prev->right=root->data;
    prev=root;
    inorder(root->right,prev);
 }

    Node* flatten(Node* root){
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        inorder(root,prev);
        prev->left=NULL;
        prev->right=NULL;

        return dummy->right;
    }
};

Input: 
          5 
        /   \ 
       3     7 
      / \   / \ 
     2   4 6   8
Output: 2 3 4 5 6 7 8
