class Solution1{
  public:
  TNode* convertToBST(vector<int> &v,int l,int h){
      if(l>h)
        return NULL;
      int mid = (l+h)/2;
      if((l+h)&1) mid++;   // for even len
      
      TNode* curr = new TNode(v[mid]);
      curr->left = convertToBST(v,l,mid-1);
      curr->right = convertToBST(v,mid+1,h);
      
      return curr;
  }
    TNode* sortedListToBST(LNode *head) {
       vector<int> v;
       while(head){
           v.push_back(head->data);
           head = head->next;
       }
       int n = v.size();
       int l=0,h=n-1;
      return convertToBST(v,l,h);
    }
};
// M-2  without space
class Solution{
  public:
    LNode* findMid(LNode* curr){
        LNode* slow = curr; LNode* fast = curr; LNode* prev = NULL;
        
        while(fast and fast->next){
            prev=slow ,slow=slow->next, fast=fast->next->next;
        }
        if(prev) prev->next = NULL;
        
        return slow;
    }
    TNode* sortedListToBST(LNode *head) {
        if(!head) return NULL;
        LNode* mid = findMid(head);
        
        TNode* root = new TNode(mid->data);
        
        if(head==mid) return root;
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        
        return root;
    }
};
