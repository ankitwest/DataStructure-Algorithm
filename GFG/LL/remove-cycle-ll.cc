
// better
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(!head or !head->next) return ;
        Node *slow=head,*fast=head,*prev=NULL;
        while(fast and fast->next){
            prev=slow, slow=slow->next, fast=fast->next->next;
            if(slow==fast) break; // Loop found
        }
        
        if(slow!=fast) return ; //No Loop
       fast = head;
       while(slow!=fast){
            prev=slow, slow=slow->next, fast=fast->next;
       }
        prev->next = NULL;
    }
};



class Solution
{
public:
  void removeLoop(Node* head){
    if(!head or !head->next) return;
      Node* slow=head;
      Node* fast=head;

      while(fast!=NULL && fast->next!=NULL){
          slow=slow->next;
          fast=fast->next->next;

          if(fast==slow) break;  //if cycle found
      }
      if(slow!=fast) return; //no cycle

      if(slow==head){
          while(fast->next!=slow){
              fast=fast->next;
          }
          fast->next=NULL;
      }else{
          fast=head;
          while(slow->next!=fast->next){
              slow=slow->next;
              fast=fast->next;
          }
          slow->next = NULL;
      }
  }
  };
