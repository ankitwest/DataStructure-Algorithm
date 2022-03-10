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
// prev curr next  // fast slow
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        
        ListNode* prev=new ListNode(0);  ListNode* dummy = prev;
        ListNode* curr = head;
        
        while(curr){
            if(curr->next and curr->val == curr->next->val){
                while(curr->next and curr->val == curr->next->val)
                    curr = curr->next;
                prev->next = curr->next;  // we did't move prev because we are not sure
            }else{  
                prev->next = curr;
                 prev = prev->next;  // making sure we have find unique element
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
