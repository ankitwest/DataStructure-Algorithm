Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    Node* head;
    if(head1->data>head2->data){
        head = head2;
        head->next=sortedMerge(head1,head2->next);
    }else {
        head = head1;
        head->next=sortedMerge(head2,head1->next);
    }
    return head;
} 
