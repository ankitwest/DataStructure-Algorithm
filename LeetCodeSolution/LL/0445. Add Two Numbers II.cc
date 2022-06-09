
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
    ListNode* reverse(ListNode* head){
        if(!head or !head->next) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex = curr->next;
        
        curr->next = prev;
        
        while(nex){
            prev = curr;
            curr = nex;
            nex = nex->next;
            curr->next = prev;
        }
        return curr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* curr = new ListNode(0); ListNode* dummy = curr;
         int ld=0; int cf=0; int n=0;
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        while(cf or l1 or l2){
            cf += (l1?l1->val:0) + (l2?l2->val:0);
            curr->next = new ListNode(cf%10);
            curr = curr->next;
            cf /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return reverse(dummy->next);
    }
};
