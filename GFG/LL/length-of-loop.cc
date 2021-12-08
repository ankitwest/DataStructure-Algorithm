class Solution
{
    public:
  int countNodesinLoop(struct Node *head)
  {
     Node* slow = head;
     Node* fast = head;
     int f =-1;
     while(fast and fast->next){
         slow = slow->next;
         fast = fast->next->next;
         if(fast==slow) {f=1;break;}
     }
     if(f==1){
         int ctr=1;
         fast = fast->next;
         while(slow!=fast){
             ctr++;
             fast = fast->next;
         }
         return ctr;
     }
     return 0;
  }
};
