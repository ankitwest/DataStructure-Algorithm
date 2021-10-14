class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(head==NULL) return head;
        Node* nextNode; Node* prevNode;
        prevNode=NULL;

        while(head){
            nextNode=head->next;
            head->next=prevNode;
            prevNode = head;
            head=nextNode;
        }
        
        return prevNode;
    }
    
};

