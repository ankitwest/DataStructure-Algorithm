class Solution2
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head==nullptr) 
            return nullptr;
        
        node* prev =NULL; node* next=NULL;
        node* curr = head;
        int cnt=0;
        while(curr and cnt<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        if(next){
            head->next = reverse(next,k);
        }
        return prev;
    }
};
