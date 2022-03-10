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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(0); ListNode* dummy = curr;
        ListNode* temp = l1; int ld=0; int cf=0; int n=0;
        
        while(l1 and l2){
            n = l1->val+l2->val;
            n+=cf;
            if(n<=9) curr->next = new ListNode(n),cf=0;
            else {
                ld = n%10; cf = n/10; curr->next = new ListNode(ld);
            }
            curr = curr->next;
            l1 = l1->next; l2 = l2->next;
        }
        while(l1){
            n = l1->val;
            n += cf;
            if(n<=9) curr->next = new ListNode(n),cf=0;
            else {
                ld = n%10; cf = n/10; curr->next = new ListNode(ld);
            }
            curr = curr->next;
            l1 = l1->next;
        }
        
        while(l2){
            n = l2->val;
            n += cf;
            if(n<=9) curr->next = new ListNode(n),cf=0;
            else {
                ld = n%10; cf = n/10; curr->next = new ListNode(ld);
            }
            curr = curr->next;
            l2 = l2->next;
        }
        if(cf>0){
            curr->next = new ListNode(cf);
        }
        return dummy->next;
    }
};

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(0); ListNode* dummy = curr;
        ListNode* temp = l1; int ld=0; int cf=0; int n=0;
        
        while(cf or l1 or l2){
            cf += (l1?l1->val:0) + (l2?l2->val:0);
            curr->next = new ListNode(cf%10);
            curr = curr->next;
            cf /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy->next;
    }
};
