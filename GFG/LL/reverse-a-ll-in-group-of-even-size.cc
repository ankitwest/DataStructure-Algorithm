

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head==nullptr) 
            return nullptr;
        
        node* prev =NULL; node* next=NULL;
        node* curr = head;
        int cnt=0;
        while(curr!=NULL and cnt<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        if(next!=NULL){
            head->next = reverse(next,k);
        }
        return prev;
    }
};


Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
