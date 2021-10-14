Recursive


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


Iterative


Node* sortedMerge(Node* head1, Node* head2)  {
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    Node* curr;
    if(head1->data<head2->data){
        curr=head1; 
        head1=head1->next;
    }else{
        curr=head2; 
        head2=head2->next;
    }
    
    Node* head = curr;
    while(head1 and head2){
        if(head1->data<head2->data){
            curr->next=head1;
            head1=head1->next;
            curr=curr->next;
        }else{
            curr->next=head2; 
            head2=head2->next;
            curr=curr->next;
        }
        
    }
    if(head2) curr->next=head2;
    else curr->next=head1;
    
    return head;
    
}
