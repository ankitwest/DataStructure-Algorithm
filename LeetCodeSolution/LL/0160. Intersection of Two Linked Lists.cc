M-1

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int l1 = 0; int l2 = 0;
        ListNode* a = head1; ListNode* b = head2;
        
        if(!a or !b) return NULL;
        
        while(a) l1++,a=a->next;
        while(b) l2++,b=b->next;
        
        if(l2>l1) swap(head1,head2),swap(l1,l2);
        
        int l = l1-l2;
        while(l--) head1=head1->next;
        
        while(head1!=head2 and head1 and head2){
            head1=head1->next;head2=head2->next;
        }
        return head1;
    }
};
        


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
