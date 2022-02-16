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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        
        while(curr and curr->next){   // while(curr->next and curr->next->next){
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            
            curr = curr->next;
            prev = prev->next->next;
        }
//         if(curr->next==NULL){
//             return dummy->next;
//         }
        
//         if(curr->next->next==NULL){
//              prev->next = curr->next;
//             curr->next = NULL;
//             prev->next->next = curr;
//         }
        
        return dummy->next;
    }
};




Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
