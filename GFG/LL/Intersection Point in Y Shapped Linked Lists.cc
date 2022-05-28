//Intersection Point in Y Shapped Linked Lists

int intersectionPoint2(Node* head1, Node* head2)
{
    Node* a = head1;
    Node* b = head2;
    int l1=0,l2=0;
    while(a) l1++,a=a->next;
    while(b) l2++,b=b->next;
    
    if(l2>l1) swap(head1,head2),swap(l1,l2);
    
    // if(l1>l2){
        int l = l1-l2;
        while(l--) head1=head1->next;
        
        while(head1!=head2){
            head1=head1->next;head2=head2->next;
        }
        return head1->data;
    // } 
}
int intersectionPoint(Node* head1, Node* head2)
{
    Node* a = head1;
    Node* b = head2;
    if(!a or !b) return -1;
    
    // while(a and b and a!=b){
    //     a = a->next;
    //     b = b->next;
        
    //     if(a==b) return a->data;
        
    //     if(!a) a = head2;
    //     if(!b) b = head1;
    // }
    
    // return -1;
    while(a!=b){
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }
    return a->data;
}
Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:

