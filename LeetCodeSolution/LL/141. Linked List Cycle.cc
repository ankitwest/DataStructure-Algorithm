class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast) return true;
        }
        
        if(fast->next==NULL or fast->next->next==NULL)
            return false;
        return false;
    }
};
