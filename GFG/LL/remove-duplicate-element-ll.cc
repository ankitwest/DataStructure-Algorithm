Node *removeDuplicates(Node *head)
{
    if(!head) return NULL;
    
     Node* curr = head;
    //  Node* temp = NULL;
     while(curr->next!=NULL){
         if(curr->data == curr->next->data){
            //  temp = curr->next;
             curr->next = curr->next->next;
            //  delete temp;
         }
         else curr = curr->next;
     }
     return head;
}
