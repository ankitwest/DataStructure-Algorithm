M-1

int findlen(ListNode* head){
        ListNode* temp = head;
        int l = 0;
        while(temp!=NULL){
            l++;
            temp = temp->next;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int l1 = findlen(head1);
        int l2 = findlen(head2);
        
         ListNode* temp1 = head1;
         ListNode* temp2 = head2;
        
        int extra=0;
        if(l2>l1){
            extra = l2-l1;
            while(extra--){
                temp2=temp2->next;
            }
        }else{
            extra = l1-l2;
            while(extra--){
                temp1=temp1->next;
            }
        }
        while(temp1!=temp2 and temp1!=NULL and temp2!=NULL){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
        
        

    }



M-2
  
 ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {

        ListNode* a = head1;
        ListNode* b = head2;
        
        while(a!=b){
            a = (a==NULL) ? head2:a->next;
            b = (b==NULL) ? head1:b->next;
        }
        return a;
 }
