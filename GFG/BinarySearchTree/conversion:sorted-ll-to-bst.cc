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
