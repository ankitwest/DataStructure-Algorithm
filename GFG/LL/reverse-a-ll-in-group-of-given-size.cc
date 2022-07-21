class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
       if(!head or k==1) return head;
       
       node* dummy = new node(0);
       dummy->next = head;
       
        int count = 0;
       node* temp = dummy; 
       while(temp) {
        temp = temp->next;
        count++;
       }
       
       node* prev = dummy; node* curr = dummy; node* next = dummy;
       while(next){
           curr = prev->next;
           next = curr->next;
           
           int kk = count>k?k:(count-1);  // 1 less than left cnt;
           for(int i=1;i<kk;i++){
              curr->next = next->next;
              next->next = prev->next;
              prev->next = next;
              next = curr->next;
           }
           prev = curr;
           count -= k;
       }
       return dummy->next;
    }
};


TC - O(N)
    SC- O(1)

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

TC - O(N)
    SC- O(N/k)
