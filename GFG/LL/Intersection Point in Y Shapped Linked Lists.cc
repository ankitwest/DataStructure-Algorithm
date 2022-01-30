//Intersection Point in Y Shapped Linked Lists


int intersectPoint(Node* head1, Node* head2)
{
    Node* h1 = head1;
    Node* h2 = head2;
    if(!h1 and !h2)
        return -1;
    while(h1 and h2 and h1!=h2){
        h1=h1->next;
        h2=h2->next;
        
        if(h1==h2)
            return h1->data;
        if(!h1)
            h1=head2;
        if(!h2)
            h2=head1;
    }
    return -1;
}

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:



class Solution
{
public:
    int cut(Node* a,Node* b,int d){
        while(d--){
            // if(a==NULL)
            //     return -1;
            a=a->next;
        }
        while(a and b){
            if(a==b)
                return a->data;
            a=a->next;
            b=b->next;
        }
    }
    
    int intersectPoint(Node* head1, Node* head2)
    {
        //
        auto count = [&](Node* head) -> int{
           int l = 0;
           while(head){
               l++;
               head = head->next;
           }
           return l;
       };
       
       int l1 = count(head1);
       int l2 = count(head2);
       
       int meet=0;
       if(l1>l2){
           int d = l1-l2;
           meet = cut(head1,head2,d);
       }else{
           int d = l2-l1;
           meet = cut(head2,head1,d);
       }
       return meet;
    }
};
