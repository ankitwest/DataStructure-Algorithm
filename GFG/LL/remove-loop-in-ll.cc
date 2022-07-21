class Solution1
{
    public:
    //Function to remove a loop in the linked list.
     void removeLoop(Node* head){
        if(!head or !head->next) return;
        Node *slow=head,*fast=head,*prev=nullptr;
    
        while(fast and fast->next){
           prev=slow , slow=slow->next , fast=fast->next->next;       
        
           if(slow==fast) break;   //if cycle found
        }
        if(slow!=fast) return;    //no cycle --> just return

        fast=head;
        while(slow!=fast){
            prev= slow , slow=slow->next , fast=fast->next;
        }

        prev->next=nullptr;
        
    }
};

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(!head or !head->next) return;
        Node* slow=head;
        Node* fast=head;
    
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
    
            if(fast==slow) break;  //if cycle found
        }
        if(slow!=fast) return; //no cycle
            
        slow = head;
        if(slow==fast){
            while(fast->next!=slow)
                fast=fast->next;
        }else{
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
        }
        fast->next=NULL;
    }
};
