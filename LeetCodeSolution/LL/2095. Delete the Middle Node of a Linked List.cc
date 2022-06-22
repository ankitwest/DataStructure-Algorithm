class Solution {
private:
    ListNode* middleNode(ListNode* &head) {
        ListNode* prev = NULL;
        ListNode* slow = head; ListNode* fast = head;
        
        while(fast!=NULL and fast->next!=NULL){
            prev = slow, slow = slow->next, fast = fast->next->next;
        }
        if(prev)
            prev->next = slow->next;
        return head;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head or !head->next) return NULL;
        
        auto temp = middleNode(head);
        return temp;
    }
};
