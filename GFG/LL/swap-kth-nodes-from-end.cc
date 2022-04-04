we are not suppose to change the data values
but instead change the connection




// M-2
Node *swapkthnode(Node* head, int num, int k)
{
    if(k>num) return head;
    if(k==num-k+1) return head;
    
    Node* dummy = new Node(-1); dummy->next = head;
    Node* p1 = dummy; Node* p2 = dummy;
    
    for(int i=1;i<k;i++){
        p1 = p1->next;
    }
    for(int i=1;i<num-k+1;i++){
        p2 = p2->next;
    }
    swap(p1->next, p2->next);
    swap(p1->next->next, p2->next->next);
    return dummy->next;
}





// M-1
Node *swapkthnodeZ(Node* head, int num, int k)
{
    if(k>num) return head;
    if(k==num-k+1) return head;
    
    Node* start = head; Node* end = head;
    Node* start_prev = NULL; Node* end_prev = NULL;
    
    for(int i=1;i<k;i++){
        start_prev = start;
        start=start->next;
    }
    for(int i=1;i<num-k+1;i++){
        end_prev = end;
        end = end->next;
    }
    
    if(start_prev!=NULL) start_prev->next = end;
    if(end_prev!=NULL) end_prev->next = start;
    
    Node* temp = start->next;
    start->next = end->next;
    end->next = temp;
    
    if(k==1) head = end;  // given in example
    if(k==num) head = start;
    return head;
}

