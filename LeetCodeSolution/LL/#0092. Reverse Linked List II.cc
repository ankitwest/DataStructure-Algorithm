class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        dummy->next = head;
        
        for(int i=1;i<left;i++) pre = pre->next;
        
        auto tail = pre->next;
        
        for(int i=1;i<=right-left;i++){
            auto temp = pre->next;
            pre->next = tail->next;
            tail->next = tail->next->next;
            pre->next->next = temp;
        }
        return dummy->next;
    }
};

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
