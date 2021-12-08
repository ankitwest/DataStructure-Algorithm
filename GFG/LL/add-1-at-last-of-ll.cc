class Solution
{
    public:
    Node* reverse(Node* head){
        Node* prev=NULL, *next=NULL;
        Node* curr = head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        head = reverse(head);
        bool f = true;
        Node* curr = head;
        while(curr!=NULL and f==true){
            if(curr->next==NULL and curr->data==9){
                Node* newNode = new Node(1);
                curr->next = newNode;
                curr->data = 0;
                f = false;
            }else if(curr->next!=NULL and curr->data==9 and curr->next->data<9){
                curr->next->data += 1;
                curr->data = 0;
                f= false;
            }else if(curr->next!=NULL and curr->data==9 and curr->next->data==9){
                curr->data = 0;
                curr=curr->next;
            }else{
                curr->data += 1;
                 f= false;
            }
        }
        return reverse(head);
    }
};
