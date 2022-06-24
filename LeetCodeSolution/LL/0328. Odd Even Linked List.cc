class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* odd = head; ListNode* even_start = head->next;
        ListNode* even = head->next;
        
        while(even and even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;
        return head;
    }
};
