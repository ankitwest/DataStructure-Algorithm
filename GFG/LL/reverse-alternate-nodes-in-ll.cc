


class Solution
{
    public:
    Node* reverse(Node* head){
        Node* prev=NULL;  Node* next=NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void rearrange(struct Node *head)
    {
         Node* curr = head; int n = 1;
         Node* odd = NULL; Node* odd_head = NULL;
         Node* even = NULL; Node* even_head = NULL;
         while(curr){
             if(n&1){
                 if(odd) odd->next = curr,odd = odd->next;
                 else odd = odd_head = curr;
             }else{
                 if(even) even->next = curr,even = even->next;
                 else even = even_head = curr;
             }
             curr = curr->next;
             n++;
         }
         Node* x = reverse(even_head);
         head = odd_head;
    }
};
