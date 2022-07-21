class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int k = right-left+1;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        left -= 1;
        while(left--){
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* next = curr->next;
        
        for(int i=1;i<k;i++){
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        
        return dummy->next;
    }
};
