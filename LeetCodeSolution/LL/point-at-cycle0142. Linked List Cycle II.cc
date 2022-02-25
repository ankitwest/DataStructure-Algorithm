

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
        ListNode* slow=head;ListNode* fast=head;
        ListNode* prev=NULL; 
        
        while(fast and fast->next){
            prev=slow,slow=slow->next,fast=fast->next->next;
            if(slow==fast) break;
        }
        if(fast==NULL or fast->next==NULL) return NULL;
        
        fast = head;
        while(slow!=fast){
             prev=slow,slow=slow->next,fast=fast->next;
        }
        return prev->next;
    }
};
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

    
    
    
    Optimize
    class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* slow=head;ListNode* fast=head;
        
        while(fast and fast->next){
            slow=slow->next,fast=fast->next->next;
            if(slow==fast) break;
        }
        if(fast==NULL or fast->next==NULL) return NULL;
        
        fast = head;
        while(slow!=fast){
             slow=slow->next,fast=fast->next;
        }
        return slow;
    }
};
    
