/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        
        for(int i=1;i<left;i++) pre = pre->next;
        
        auto tail = pre->next;
        
        for(int i=1;i<right-left+1;i++){
            auto temp = pre->next;
            pre->next = tail->next;
            tail->next = tail->next->next;
            pre->next->next = temp;
        }
        return dummy->next;
    }
};
