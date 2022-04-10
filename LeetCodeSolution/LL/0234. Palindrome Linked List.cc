


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
    ListNode* reverseList(ListNode* head){
        if(head==NULL or head->next==NULL) return head;
        
        ListNode* dummy=NULL;
        ListNode* nex=head->next;
        
        head->next=dummy;
        while(nex!=NULL){
            dummy=head;
            head=nex;
            nex=nex->next;
            head->next=dummy;
        }
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL) return true;
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // ListNode* rev=reverseList(slow->next);
        // slow->next=rev;
        
        slow->next=reverseList(slow->next);
        slow=slow->next;
        
        while(slow!=NULL){
            if(slow->val!=head->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};

Input: head = [1,2,2,1]
Output: true
