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
//     ListNode* rev(ListNode* head){  //old
//         if(head or head->next) return head;
        
//         ListNode* dummy = NULL;
//         ListNode* nex = head->next;
//         head->next = dummy;
        
//         while(nex!=NULL){
//             dummy=head;
//             head=nex;
//             nex=nex->next;
//             head->next=dummy;
//         }
//         return head;
//     }
    ListNode* rev(ListNode* head){
        if(head or head->next) return head;
        
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            next = head->next;
            head->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head or head->next) return true;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = rev(slow->next);
        slow = slow->next;
        
        while(slow){
            if(slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
