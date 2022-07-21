/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        
        ListNode* slow = head;ListNode* fast = head;
        ListNode* prev = NULL; 
        
        while(fast and fast->next){
            prev = slow,slow = slow->next,fast = fast->next->next;
            if(slow==fast) break;
        }
        if(fast==NULL or fast->next==NULL) return NULL;
        
        fast = head;
        while(slow!=fast){
             prev = slow,slow = slow->next,fast = fast->next;
        }
        // prev->next = nullptr;  to remove the loop
        return prev->next;
    }
};
